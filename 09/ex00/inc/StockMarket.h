#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <cstdlib>
#include "colors.h"
#include "printUtils.h"
#include "Date.h"
#include "utils.h"

#define DATA_PATH "inc/data.csv"

class StockMarket {
public:
	typedef std::map<date, float>::const_iterator const_iterator;
	StockMarket();
	StockMarket(const std::map<date, float> &prices);
	StockMarket(const StockMarket &src);
	StockMarket &operator=(const StockMarket &rhs);
	float operator[](const date &idx) const;
	void printMarket();
	float at(const date &date) const;

private:
	std::map<date, float> _prices;
	void _loadData();
};
