#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <climits>

#define ANSI_ESC_CLS "\033[2J"
#define ANSI_ESC_HOME "\033[H"
#define BANNER "\
  ____  _ _            _         ______          _                            \n\
 |  _ \\(_) |          (_)       |  ____|        | |                           \n\
 | |_) |_| |_ ___ ___  _ _ __   | |__  __  _____| |__   __ _ _ __   __ _  ___ \n\
 |  _ <| | __/ __/ _ \\| | '_ \\  |  __| \\ \\/ / __| '_ \\ / _` | '_ \\ / _` |/ _ \\\n\
 | |_) | | || (_| (_) | | | | | | |____ >  < (__| | | | (_| | | | | (_| |  __/\n\
 |____/|_|\\__\\___\\___/|_|_| |_| |______/_/\\_\\___|_| |_|\\__,_|_| |_|\\__, |\\___|\n\
                                                                    __/ |     \n\
                                                                   |___/      \n\
"

#define DATABASE_FILE "data.csv"
#define DATABASE_URL "https://codeberg.org/27/cpp-modules/raw/commit/8ae8a39f3cdfc3c1f3bf3fa4b48a67dd4483614f/module-09/ex00/data.csv"
#define DATABASE_SHA256 "6b7bef1ae66b8cefee20b16ce9018bddf41ad97a711d5e6a20493d20d79a1c94"

namespace btc {
namespace utils {

static bool checkFileExists(const std::string &file) {
	struct stat buffer;
	return (stat(file.c_str(), &buffer) == 0);
}

static bool checkFileReadable(const std::string &file) {
	std::ifstream fileCheck(file.c_str());
	return (fileCheck.good());
}

static bool checkFileValid(btc::log::Logger &logger, const std::string type, const std::string &file) {
	if (!checkFileExists(file)) {
		logger.log(btc::log::ERROR) << type << " file '" << file << "' does not exist";
		return (false);
	}
	if (!checkFileReadable(file)) {
		logger.log(btc::log::ERROR) << type << " file '" << file << "' is not readable";
		return (false);
	}
	return (true);
}

static std::string spawn(const std::string &command) {
	std::string output;
	FILE *stream = popen(command.c_str(), "r");
	if (stream) {
		char buffer[1024];
		while (fgets(buffer, 128, stream) != NULL) {
			output += buffer;
		}
		pclose(stream);
	}
	return (output);
}

static bool commandPath(const std::string &command, std::string &path) {
	path = spawn("command -v " + command);
	return (path.size() > 0);
}

static bool commandExists(const std::string &command) {
	std::string path;
	return (commandPath(command, path));
}

static bool downloadFile(btc::log::Logger &logger, const std::string &file, const std::string &url) {
	logger.trace() << "Trying to download '" << file << "' from '" << url << "'";
	std::string path;
	if (commandPath("curl", path)) {
		logger.trace() << "Using 'curl' found at '" << path << "'";
		std::string command = "curl -sSL -o " + file + " " + url;
		spawn(command);
	} else if (commandPath("wget", path)) {
		logger.trace() << "Using 'wget' found at '" << path << "'";
		std::string command = "wget -O " + file + " " + url;
		spawn(command);
	} else {
		logger.warn() << "Neither 'curl' nor 'wget' are installed, cannot download file.";
		return (false);
	}
	return (checkFileExists(file));
}

static bool checkSha256(btc::log::Logger &logger, const std::string &file, const std::string &sha256) {
	logger.trace() << "Checking sha256 of file '" << file << "'";
	if (!commandExists("sha256sum")) {
		logger.warn() << "Cannot validate file hash, command 'sha256sum' not found, skipping...";
		return (true);
	}
	std::string output = spawn("sha256sum " + file);
	if (output.size() == 0) {
		logger.warn() << "Failed to check sha256 of file '" << file << "'";
		return (false);
	}
	std::string expectedSha256 = sha256;
	std::string actualSha256 = output.substr(0, output.find(' '));
	logger.trace() << "Expected sha256 is '" << expectedSha256 << "'";
	logger.trace() << "Actual sha256 is '" << actualSha256 << "'";
	if (expectedSha256 != actualSha256) {
		logger.warn() << "Sha256 of file '" << file << "' is invalid, expected '" << expectedSha256 << "', got '" << actualSha256 << "'";
		return (false);
	}
	return (true);
}

} // namespace utils
} // namespace btc

int main(int argc, char **argv) {
	std::cout << BANNER << std::endl;

	if (argc != 2) {
		std::cerr << "Please provide an input file" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return (1);
	}

	btc::log::Logger logger("main");

	logger.trace() << "Checking input file";
	const std::string inputFile(argv[1]);
	// First check if the input file is valid
	if (!btc::utils::checkFileValid(logger, "Input", inputFile)) {
		return (1);
	}

	const std::string databaseFile(DATABASE_FILE);
	// Special case for if the database file doesn't exist
	if (!btc::utils::checkFileExists(databaseFile)) {
		logger.log(btc::log::INFO, false) << "Database file '" << DATABASE_FILE << "' is missing" << btc::log::endl \
			<< "Do you want to download it? (Y/n): ";
		char answer;
		std::cin >> answer;
		if (answer != 'Y' && answer != 'y') {
			return (1);
		}
		if (!btc::utils::downloadFile(logger, databaseFile, DATABASE_URL)) {
			logger.critical() << "Failed to download database file, please download it manually.";
			return (1);
		}
		if (!btc::utils::checkSha256(logger, databaseFile, DATABASE_SHA256)) {
			logger.critical() << "Failed to check sha256 of downloaded database file, please download it manually.";
			return (1);
		}
		logger.info() << "Database file downloaded successfully";
	}

	// Finally, check the database file
	if (!btc::utils::checkFileValid(logger, "Database", databaseFile)) {
		return (1);
	}

	btc::log::Logger parserLogger("parser");

	int earliestYear = INT_MAX;
	std::map<std::string, double> data;
	if (!btc::parser::loadDatabase(parserLogger, data, databaseFile, earliestYear)) {
		return (1);
	}
	logger.debug() << "Loaded " << data.size() << " database rows";

	return (btc::parser::processUserInput(parserLogger, data, inputFile, earliestYear) != true);
}
