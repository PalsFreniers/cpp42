#pragma once

#include <map>
#include <string>


class BitcoinExchange
{
        public:
                BitcoinExchange(void);
                ~BitcoinExchange(void);
                bool process(const std::string &date, const double multiplier, const int &earliestYear);

                bool loadDatabase(const std::string &file, int &earliestYear);
                bool processUserInput(const std::string &file, const int &earliestYear);
        private:
                BitcoinExchange(BitcoinExchange &copy);
                BitcoinExchange& operator=(const BitcoinExchange& x);
                std::map<std::string, double> _data;
};
