#include "../inc/StockMarket.h"

StockMarket::StockMarket() {
        _loadData();
}

StockMarket::StockMarket(const std::map<date, float>& prices) {
        _prices = prices;
}

StockMarket::StockMarket(const StockMarket& src) {
        *this = src;
}

StockMarket& StockMarket::operator=(const StockMarket& rhs) {
        _prices = rhs._prices;
        return *this;
}


float StockMarket::operator[](const date& idx) const {
        auto it = _prices.begin();
        if(_prices.find(idx) != _prices.end()) return _prices.at(idx);
        for(; it != _prices.end(); ++it) if(it->first > idx) break;
        return it != _prices.end() ? it->second : (--_prices.end())->second;
}

void StockMarket::_loadData() {
        std::ifstream data(DATA_PATH);
        auto line = std::string("");
        std::getline(data, line);
        while(!data.eof()) {
                std::getline(data, line);
                if(line.empty()) continue;
                auto tmpDate = extractDate(line, ',');
                auto tmpRate = extractRate(line, 11);
                _prices.insert(_prices.end(), std::pair<date, float>(tmpDate, tmpRate));
        }
        data.close();
}

void StockMarket::printMarket() {
        for(auto it = _prices.begin(); it != _prices.end(); ++it) {
                it->first.print();
                PRINT ": " BYLW AND it->second AND CLR ENDL;
        }
}

float StockMarket::at(const date& date) const {
        return (*this)[date];
}
