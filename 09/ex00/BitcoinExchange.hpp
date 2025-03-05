#pragma once

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>   // STL Container
#include <list>  // STL Container
#include <sstream>
#include <string>

namespace btc {
	namespace log {
		static const std::string endl = "\n";

		enum Level {
			ALL = 0,
			TRACE,
			DEBUG,
			INFO,
			WARN,
			ERROR,
			CRITICAL,
		};

		Level levelFromString(const std::string &level);

		class Logger;

		class LogStream {
			public:
				~LogStream(void);
				LogStream(Logger& logger, Level level, bool shouldEndl);
				LogStream(LogStream &copy);
				template <typename T>
				LogStream& operator<<(T const& x) {
					stream << x;
					return (*this);
				}
			private:
				LogStream(void);
				LogStream& operator=(const LogStream& x);
				Logger& logger;
				Level level;
				bool shouldEndl;
				std::ostringstream stream;
		};

		class Logger {
			public:
				~Logger(void);
				Logger(const std::string name);
				Logger& operator=(const Logger& x);
	
				std::string const& getName(void) const;
				Level getLevel(void) const;
				void setLevel(Level level);

				LogStream log(Level level, bool shouldEndl = true);
				void log(Level level, const std::string &message, bool shouldEndl = true);
				LogStream trace(void);
				LogStream debug(void);
				LogStream info(void);
				LogStream warn(void);
				LogStream error(void);
				LogStream critical(void);
			private:
				Logger(void);
				Logger(Logger &copy);
				std::string name;
				Level minLevel;
		};
	}

	namespace parser {
		bool loadDatabase(btc::log::Logger &logger, std::map<std::string, double> &data, const std::string &file, int &earliestYear);
		bool processUserInput(btc::log::Logger &logger, const std::map<std::string, double> &data, const std::string &file, const int &earliestYear);
	}

	class BitcoinExchange
	{
		public:
			~BitcoinExchange(void);
			static bool runTheNumbers(const std::map<std::string, double> &data, const std::string &date, const double multiplier, const int &earliestYear);
		private:
			BitcoinExchange(void);
			BitcoinExchange(BitcoinExchange &copy);
			BitcoinExchange& operator=(const BitcoinExchange& x);
			static btc::log::Logger logger;
	};
}
