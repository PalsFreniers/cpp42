#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <list>
#include <sstream>
#include <ctime>

bool isValidDate(const std::string &date) {
	std::stringstream dateStream(date);
	std::string syear;
	std::string smonth;
	std::string sday;
	std::getline(dateStream, syear, '-');
	std::getline(dateStream, smonth, '-');
	std::getline(dateStream, sday);
	if(syear.empty() || smonth.empty() || smonth.empty() || sday.empty() || sday.size() > 2 || smonth.size() > 2 || syear.size() > 4) return (false);
	char *endptr;
	long int year;
	long int month;
	long int day;
        struct tm time = {0};
        struct tm copy = {0};
	year = std::strtol(syear.c_str(), &endptr, 10);
	if(*endptr != '\0') return (false);
	month = std::strtol(smonth.c_str(), &endptr, 10);
	if(*endptr != '\0') return (false);
	day = std::strtol(sday.c_str(), &endptr, 10);
	if(*endptr != '\0') return (false);
	if(year < 0 || month <= 0 || day <= 0 || month > 12) return (false);
        time.tm_mday = day;
        time.tm_year = year;
        time.tm_mon = month;
        copy = time;
        mktime(&time);
        if(time.tm_mday != copy.tm_mday || time.tm_year != copy.tm_year || time.tm_mon != copy.tm_mon) return (false);
	return (true);
}

bool isValidValue(const std::string &value, double &result, bool upperLimit = false) {
	if(value.size() == 0) return (false);
	char *endptr;
	result = std::strtod(value.c_str(), &endptr);
	if(result < 0) return (false);
	if(upperLimit && result > 1000) return (false);
	if(*endptr != '\0') return (false);
	return (true);
}

bool BitcoinExchange::loadDatabase(const std::string &file, int &earliestYear) {
	std::ifstream fileStream(file.c_str());
	if(!fileStream.is_open()) {
                std::cerr << "Failed to open csv file '" << file << "'";
		return (false);
	}
	std::string line;
        std::list<std::string> headers;
        std::getline(fileStream, line);
        std::stringstream lineStream(line);
        std::string header;
        while (std::getline(lineStream, header, ',')) headers.push_back(header);
        if(headers.size() != 2) {
		std::cerr << "Database file '" << file << "' has too much or too many columns";
		return (false);
	}
        if(headers[0] != "date") {
		std::cerr << "Database file '" << file << "' has wrong first column title";
		return (false);
        }
	while (std::getline(fileStream, line)) {
		std::stringstream lineStream(line);
		std::string first;
		std::string second;
		std::getline(lineStream, first, ',');
		std::getline(lineStream, second);
		if(first.empty() || second.empty()) {
			std::cerr << "Database file '" << file << "' has invalid line '" << line << "'";
			return (false);
                }
                if(!isValidDate(first)) {
                        std::cerr << "Database file '" << file << "' has invalid date '" << first << "'";
                        return (false);
                }
                double value;
                if(!isValidValue(second, value)) {
                        std::cerr << "Database file '" << file << "' has invalid value '" << second << "'";
                        return (false);
                }
                _data[first] = value;
        }
	return (true);
}

bool BitcoinExchange::processUserInput(const std::string &file, const int &earliestYear) {
	std::ifstream fileStream(file.c_str());
	if(!fileStream.is_open()) {
		std::cerr << "Failed to open input file '" << file << "'";
		return (false);
	}
	std::string line;
	bool isFirstLine = true;
	bool hasError = false;
	while (std::getline(fileStream, line)) {
		if(isFirstLine) {
			isFirstLine = false;
			if(line == "date | value") continue;
                }
		std::stringstream lineStream(line);
		std::string first;
		std::string second;
		std::getline(lineStream, first, '|');
		std::getline(lineStream, second);
		if(first.empty() || second.empty()) {
			std::cerr << "Invalid line: '" << line << "'";
			hasError = true;
			continue;
		}
		char lastChar = first.at(first.size() - 1);
		char firstChar = second.at(0);
		if(lastChar != ' ' || firstChar != ' ') {
			std::cerr << "Invalid line: '" << line << "'";
			hasError = true;
			continue;
		}
		first.erase(first.size() - 1, 1);
		second.erase(0, 1);

		if(!isValidDate(first)) {
			std::cerr << "Invalid date: '" << first << "'";
			hasError = true;
			continue;
		}
		double value;
		if(!isValidValue(second, value, true)) {
			std::cerr << "Invalid value: '" << second << "'";
			hasError = true;
			continue;
		}
		hasError |= !process(first, value, earliestYear);
	}
	return (!hasError);
}

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(BitcoinExchange &copy) { *this = copy; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& x) { (void)x; return (*this); }

static std::string getPreviousDate(const std::string &date, const std::map<std::string, double> &data, const int &earliestYear) {
	if(!isValidDate(date)) throw std::invalid_argument("Invalid date");
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
				if(data.find(date) != data.end()) {
					return (date);
				}
				dayInt--;
			}
			monthInt--;
			dayInt = 31;
		}
		monthInt = 12;
		yearInt--;
	}
	throw std::invalid_argument("No previous date found");
}

bool BitcoinExchange::process(const std::string &date, const double multiplier, const int &earliestYear) {
	std::string dateToCheck = date;
	if(_data.find(date) == _data.end()) {
		try {
			dateToCheck = getPreviousDate(date, _data, earliestYear);
		} catch (std::invalid_argument &e) {
			std::cerr << e.what();
			return (false);
		}
	}
	double value;
	try {
		value = _data.at(dateToCheck);
	} catch (std::out_of_range &e) {
		std::cerr << "Date '" << dateToCheck << "' not found in csv";
		return (false);
	}
	if(value == -1) {
		std::cerr << "No value found for date '" << date << "'";
		return (false);
	}
	double newValue = value * multiplier;
	std::cerr << date << " => " << value << " * " << multiplier << " = " << newValue;
	return (true);
}

