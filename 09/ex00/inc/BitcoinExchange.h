#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <climits>
#include <cstdlib>
#include "Date.h"
#include "StockMarket.h"
#include "colors.h"
#include "printUtils.h"
#include "utils.h"

class BitcoinExchange {
public:
        typedef std::multimap<date, float>::iterator iterator;
        typedef std::multimap<date, float>::const_iterator const_iterator;
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator = (const BitcoinExchange &rhs);
        const_iterator cbegin() const;
        const_iterator cend() const;
        void loadFile(const std::string &filePath);
        void printValue(const StockMarket &market) const;
private:
        std::multimap<date, float> _wallet;
};
