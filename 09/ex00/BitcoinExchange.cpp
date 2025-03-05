#include "BitcoinExchange.hpp"

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

namespace btc {
namespace log {

bool levelFromString(const std::string &level, Level &result) {
	static const std::string levels[] = {
		"ALL",
		"TRACE",
		"DEBUG",
		"INFO",
		"WARN",
		"ERROR",
		"CRITICAL",
	};

	for (int i = 0; i < CRITICAL; i++) {
		if (level == levels[i]) {
			result = static_cast<Level>(i);
			return (false);
		}
	}
	return (true);
}

// --- LogStream ---

LogStream::~LogStream(void) {
	std::string message = stream.str();
	if (message.size() > 0) {
		logger.log(level, message, shouldEndl);
	}
}

LogStream::LogStream(Logger& logger, Level level, bool shouldEndl) : logger(logger), level(level), shouldEndl(shouldEndl) {}
LogStream::LogStream(LogStream &copy) : logger(copy.logger), level(copy.level), stream(copy.stream.str()) {}

LogStream& LogStream::operator=(const LogStream& x) {
	if (this != &x) {
		logger = x.logger;
		level = x.level;
		stream << x.stream.str();
	}
	return (*this);
}

// --- Logger ---

Logger::~Logger(void) {}
Logger::Logger(const std::string name): name(name), minLevel(INFO) {
	const char *env = std::getenv("BTC_LOG_LEVEL");
	if (env == NULL) {
		std::string envName = "BTC_" + name + "_LOG_LEVEL";
		transform(envName.begin(), envName.end(), envName.begin(), ::toupper);
		env = std::getenv(envName.c_str());
	}
	if (env != NULL && levelFromString(env, minLevel)) {
		log(WARN) << "Invalid log level '" << env << "' for logger '" << name << "', using INFO instead" << endl;
	}
}

Logger::Logger(Logger &copy) { *this = copy; }

Logger& Logger::operator=(Logger const& x) {
	if (this != &x) {
		name = x.name;
		minLevel = x.minLevel;
	}
	return (*this);
}

std::string const& Logger::getName(void) const { return name; }
Level Logger::getLevel(void) const { return minLevel; }
void Logger::setLevel(Level level) { minLevel = level; }

LogStream Logger::log(Level level, bool shouldEndl) {
	LogStream stream(*this, level, shouldEndl);

	return stream;
}

#define GEN_LEVEL_FN(level, upper) \
	LogStream Logger::level(void) { LogStream stream(*this, upper, true); return stream; }
GEN_LEVEL_FN(trace, TRACE)
GEN_LEVEL_FN(debug, DEBUG)
GEN_LEVEL_FN(info, INFO)
GEN_LEVEL_FN(warn, WARN)
GEN_LEVEL_FN(error, ERROR)
GEN_LEVEL_FN(critical, CRITICAL)
#undef GEN_LEVEL_FN

std::ostream& operator<<(std::ostream& stream, const btc::log::Level& level) {
	switch (level) {
		case btc::log::TRACE: stream << "TRACE"; break;
		case btc::log::DEBUG: stream << "DEBUG"; break;
		case btc::log::INFO: stream << "INFO"; break;
		case btc::log::WARN: stream << "WARN"; break;
		case btc::log::ERROR: stream << "ERROR"; break;
		case btc::log::CRITICAL: stream << "CRITICAL"; break;
		case btc::log::ALL: stream << "ALL"; break;
	}
	return (stream);
}

void Logger::log(Level level, const std::string &message, bool shouldEndl) {
	if (level >= minLevel) {
		std::ostream &stream = level >= WARN ? std::cerr : std::cout;
		char timeBuffer[65];
		timeBuffer[0] = '[';
		time_t now = std::time(NULL);
		std::strftime(timeBuffer + 1, sizeof(timeBuffer) - 1, "%H:%M:%S", std::localtime(&now));
		stream << timeBuffer << "] [" << name << "/" << level << "]: " << message;
		if (shouldEndl) {
			stream << endl;
		}
	}
}

} // namespace log

namespace parser {

static bool isValidDate(const std::string &date, int &earliestYear) {
	std::stringstream dateStream(date);
	std::string year;
	std::string month;
	std::string day;
	std::getline(dateStream, year, '-');
	std::getline(dateStream, month, '-');
	std::getline(dateStream, day);
	if (year.size() == 0 || month.size() == 0 || month.size() > 2 || day.size() == 0 || day.size() > 2) {
		return (false);
	}
	char *endptr;
	long int yearInt;
	long int monthInt;
	long int dayInt;
	yearInt = std::strtol(year.c_str(), &endptr, 10);
	if (*endptr != '\0') {
		return (false);
	}
	monthInt = std::strtol(month.c_str(), &endptr, 10);
	if (*endptr != '\0') {
		return (false);
	}
	dayInt = std::strtol(day.c_str(), &endptr, 10);
	if (*endptr != '\0') {
		return (false);
	}
	if (yearInt < 0 || monthInt <= 0 || dayInt <= 0 || monthInt > 12) {
		return (false);
	}
	bool isLeapYear = false;
	if (yearInt % 4 == 0) {
		if (yearInt % 100 == 0) {
			if (yearInt % 400 == 0) {
				isLeapYear = true;
			}
		} else {
			isLeapYear = true;
		}
	}
	int daysInMonth = 0;
	switch (monthInt) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			daysInMonth = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			daysInMonth = 30;
			break;
		case 2:
			if (isLeapYear) {
				daysInMonth = 29;
			} else {
				daysInMonth = 28;
			}
			break;
	}
	if (dayInt > daysInMonth) {
		return (false);
	}
	if (yearInt < earliestYear) {
		earliestYear = yearInt;
	}
	return (true);
}

static bool isValidValue(const std::string &value, double &result, bool upperLimit = false) {
	if (value.size() == 0) {
		return (false);
	}
	char *endptr;
	result = std::strtod(value.c_str(), &endptr);
	if (result < 0) {
		return (false);
	}
	if (upperLimit && result > 1000) {
		return (false);
	}
	if (*endptr != '\0') {
		return (false);
	}
	return (true);
}

bool loadDatabase(btc::log::Logger &logger, std::map<std::string, double> &data, const std::string &file, int &earliestYear) {
	logger.trace() << "Loading database file '" << file << "'";

	std::ifstream fileStream(file.c_str());
	if (!fileStream.is_open() || !fileStream.good()) {
		logger.critical() << "Failed to open database file '" << file << "'";
		return (false);
	}

	
	std::string allowedHeaders[] = {"date", "exchange_rate"};
	std::string line;
	std::list<std::string> actualHeaders;
	{
		std::getline(fileStream, line);
		std::stringstream lineStream(line);
		std::string header;
		while (std::getline(lineStream, header, ',')) {
			actualHeaders.push_back(header);
		}
	}
	if (std::find(actualHeaders.begin(), actualHeaders.end(), "date") == actualHeaders.end()) {
		logger.critical() << "Database file '" << file << "' is missing 'date' header";
		return (false);
	}
	if (std::find(actualHeaders.begin(), actualHeaders.end(), "exchange_rate") == actualHeaders.end()) {
		logger.critical() << "Database file '" << file << "' is missing 'exchange_rate' header";
		return (false);
	}
	if (actualHeaders.size() != ARRAY_SIZE(allowedHeaders)) {
		logger.critical() << "Database file '" << file << "' has invalid headers";
		return (false);
	}

	// Is date the first or second header
	bool isFirstHeader = std::find(actualHeaders.begin(), actualHeaders.end(), "date") == actualHeaders.begin();
	
	// Then, read the CSV data
	while (std::getline(fileStream, line)) {
		// logger.trace() << "Parsing line '" << line << "'";
		std::stringstream lineStream(line);
		std::string first;
		std::string second;
		std::getline(lineStream, first, ',');
		std::getline(lineStream, second);
		if (first.size() == 0 || second.size() == 0) {
			logger.critical() << "Database file '" << file << "' has invalid line '" << line << "'";
			return (false);
		}
		if (isFirstHeader) {
			if (!isValidDate(first, earliestYear)) {
				logger.critical() << "Database file '" << file << "' has invalid date '" << first << "'";
				return (false);
			}
			double value;
			if (!isValidValue(second, value)) {
				logger.critical() << "Database file '" << file << "' has invalid value '" << second << "'";
				return (false);
			}
			data[first] = value;
		} else {
			if (!isValidDate(second, earliestYear)) {
				logger.critical() << "Database file '" << file << "' has invalid date '" << second << "'";
				return (false);
			}
			double value;
			if (!isValidValue(first, value)) {
				logger.critical() << "Database file '" << file << "' has invalid value '" << first << "'";
				return (false);
			}
			data[second] = value;
		}
	}
	return (true);
}

bool processUserInput(btc::log::Logger &logger, const std::map<std::string, double> &data, const std::string &file, const int &earliestYear) {
	logger.trace() << "Processinguser input file '" << file << "'";

	std::ifstream checkStream(file.c_str(), std::ios::in|std::ios::binary);
	if (!checkStream.is_open() || !checkStream.good()) {
		logger.critical() << "Failed to open input file '" << file << "'";
		return (false);
	}
	char buffer[10];
	checkStream.read(buffer, 10);
	checkStream.close();
	if (buffer[0] == 0x7F && buffer[1] == 'E' && buffer[2] == 'L' && buffer[3] == 'F') {
		logger.critical() << "Input file '" << file << "' is an ELF file, please provide a text file.";
		return (false);
	}

	std::ifstream fileStream(file.c_str());
	if (!fileStream.is_open() || !fileStream.good()) {
		logger.critical() << "Failed to open database file '" << file << "'";
		return (false);
	}

	std::string line;
	bool isFirstLine = true;
	bool hasError = false;
	while (std::getline(fileStream, line)) {
		if (isFirstLine) {
			isFirstLine = false;
			if (line == "date | value") {
				// By convention, the first line should be a header describing the columns type
				// We don't need it, so we won't require it.
				// The subject also clearly states that "every line" should *follow* this format,
				// thus the first line being the header technically is invalid in itself.
				//
				// whatever 42, you do you.
				continue;
			}
		}
		std::stringstream lineStream(line);
		std::string first;
		std::string second;
		std::getline(lineStream, first, '|');
		std::getline(lineStream, second);
		
		if (first.size() == 0 || second.size() == 0) {
			logger.error() << "Invalid line: '" << line << "'";
			hasError = true;
			continue;
		}
		// get tht last char of a string (.back() is not a thing)
		char lastChar = first.at(first.size() - 1);
		char firstChar = second.at(0);
		if (lastChar != ' ' || firstChar != ' ') {
			logger.error() << "Invalid line: '" << line << "'";
			hasError = true;
			continue;
		}
		first.erase(first.size() - 1, 1);
		second.erase(0, 1);

		int ignored = 0;
		if (!isValidDate(first, ignored)) {
			logger.error() << "Invalid date: '" << first << "'";
			hasError = true;
			continue;
		}
		double value;
		if (!isValidValue(second, value, true)) {
			logger.error() << "Invalid value: '" << second << "'";
			hasError = true;
			continue;
		}
		hasError |= !BitcoinExchange::runTheNumbers(data, first, value, earliestYear);
	}
	return (!hasError);
}

} // namespace parser

log::Logger BitcoinExchange::logger("exchange");

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(BitcoinExchange &copy) { *this = copy; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& x) { (void)x; return (*this); }

// Get a date that comes before the given one, error if there is none
static std::string getPreviousDate(const std::string &date, const std::map<std::string, double> &data, const int &earliestYear) {
	int ignored = 0;
	if (!parser::isValidDate(date, ignored)) {
		throw std::invalid_argument("Invalid date");
	}
	std::stringstream dateStream(date);
	std::string year;
	std::string month;
	std::string day;
	std::getline(dateStream, year, '-');
	std::getline(dateStream, month, '-');
	std::getline(dateStream, day);
	int yearInt;
	int monthInt;
	int dayInt;
	yearInt = std::strtol(year.c_str(), NULL, 10);
	monthInt = std::strtol(month.c_str(), NULL, 10);
	dayInt = std::strtol(day.c_str(), NULL, 10);

	while (yearInt >= earliestYear) {
		while (monthInt > 0) {
			while (dayInt > 0) {
				std::stringstream dateStream;
				dateStream << yearInt << "-" << monthInt << "-" << dayInt;
				std::string date = dateStream.str();
				if (data.find(date) != data.end()) {
					return (date);
				}
				dayInt--;
			}
			monthInt--;
			dayInt = 31; // let's put the highest possible value, since we know we're not gonna find bad data
		}
		monthInt = 12;
		yearInt--;
	}
	throw std::invalid_argument("No previous date found");
}

bool BitcoinExchange::runTheNumbers(const std::map<std::string, double> &data, const std::string &date, const double multiplier, const int &earliestYear) {
	std::string dateToCheck = date;
	if (data.find(date) == data.end()) {
		// If the date is not in the database, we need to check if there is a previous date
		try { // look mom i know how to throw exceptions
			dateToCheck = getPreviousDate(date, data, earliestYear);
		} catch (std::invalid_argument &e) {
			logger.error() << "Invalid date '" << date << "' (" << e.what() << ")";
			return (false);
		}
	}
	double value;
	try {
		value = data.at(dateToCheck);
	} catch (std::out_of_range &e) {
		logger.error() << "Date '" << dateToCheck << "' not found in database";
		return (false);
	}
	if (value == -1) {
		logger.error() << "No value found for date '" << date << "'";
		return (false);
	}
	double newValue = value * multiplier;
	logger.info() << date << " => " << value << " * " << multiplier << " = " << newValue;
	return (true);
}

} // namespace btc
