#pragma once

#include "printUtils.h"
#include "Date.h"
#include "StockMarket.h"
#include <string>

date extractDate(std::string &line, char c);
float extractRate(std::string &line, int start);
