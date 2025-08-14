#include "../inc/BitcoinExchange.h"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
        *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
        _wallet = rhs._wallet;
        return *this;
}

BitcoinExchange::const_iterator BitcoinExchange::cbegin() const {
        return _wallet.begin();
}

BitcoinExchange::const_iterator BitcoinExchange::cend() const {
        return _wallet.end();
}

void BitcoinExchange::loadFile(const std::string& filePath) {
        std::ifstream file(filePath.c_str());
        if(!file.is_open()) throw std::logic_error("Couldn't open the file");
        auto line = std::string("");
        std::getline(file, line);
        while(!file.eof()) {
                std::getline(file, line);
                if(line.empty()) continue;
                if(line.length() < 13 || line.at(11) != '|') {
                        ERROR BRED "Line doesn't follow format \"date | format\"" CLR ENDL;
                        ERROR TAB BBLK AND line AND CLR ENDL;
                        continue;
                }
                try {
                        auto tmpDate = extractDate(line, ' ');
                        auto tmpNum = extractRate(line, 13);
                        if(tmpNum > 1000) throw std::overflow_error("Too much BTC");
                        _wallet.insert(_wallet.end(), std::pair<date, float>(tmpDate, tmpNum));
                } catch(std::exception &e) {
                        ERROR BRED AND e.what() AND CLR ENDL;
                        ERROR TAB BBLK AND line AND CLR ENDL;
                        continue;
                }
        }
}

void BitcoinExchange::printValue(const StockMarket &market) const {
        for(BitcoinExchange::const_iterator it = cbegin(); it != cend(); ++it) {
                it->first.print();
                PRINT "=> " BYLW AND it->second;
                PRINT CLR " = " BGRN AND it->second * market[it->first] AND CLR ENDL;
        }
}
