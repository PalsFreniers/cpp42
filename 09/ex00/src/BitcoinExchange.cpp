
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

static date extractDate(std::string &line);
static float extractAmount(std::string &line);

void BitcoinExchange::loadFile(const std::string& filePath) {
        std::ifstream	file(filePath.c_str());
        std::string		line;
        date			tmpDate;
        float			tmpNum;

        if(!file.is_open()) throw std::logic_error("Couldn't open the file");

        std::getline(file, line);
        if(line != "date | value") throw std::logic_error("File doesn't follow format \"date | format\"");

        while(!file.eof()) {
                std::getline(file, line);
                if(line.length() < 13 || line.at(11) != '|') {
                        ERROR BRED "Line doesn't follow format \"date | format\"" CLR ENDL;
                        ERROR TAB BBLK AND line AND CLR ENDL;
                        continue;
                }
                try {
                        tmpDate = extractDate(line);
                } catch(std::exception &e) {
                        ERROR BRED AND e.what() AND CLR ENDL;
                        ERROR TAB BBLK AND line AND CLR ENDL;
                        continue;
                }
                try {
                        tmpNum = extractAmount(line);
                } catch(std::exception &e) {
                        ERROR BRED AND e.what() AND CLR ENDL;
                        ERROR TAB BBLK AND line AND CLR ENDL;
                        continue;
                }
                _wallet.insert(_wallet.end(), std::pair<date, float>(tmpDate, tmpNum));
        }
}

static date extractDate(std::string &line) {
        int		year;
        int		month;
        int		day;
        char	*end;

        errno = 0;
        year = strtol(line.c_str(), &end, 10);
        if(errno == ERANGE || end[0] != '-')
                throw std::out_of_range("Invalid Year");
        month = strtol(&line.at(5), &end, 10);
        if(errno == ERANGE || end[0] != '-')
                throw std::out_of_range("Invalid Month");
        day = strtol(&line.at(8), &end, 10);
        if(errno == ERANGE || end[0] != ' ')
                throw std::out_of_range("Invalid Day");
        return date(year, month, day);
}

static float extractAmount(std::string &line) {
        float	rate;
        char	*end;

        errno = 0;
        rate = strtof(&line.at(13), &end);
        if(errno == ERANGE || rate > 1000)
                throw std::overflow_error("Too much BTC");
        if(rate < 0)
                throw std::domain_error("Rate cannot be negative");
        if(end[0] != '\0')
                throw std::logic_error("Invalid line");
        return rate;
}

void BitcoinExchange::printValue(const StockMarket &market) const {
        for(BitcoinExchange::const_iterator it = cbegin(); it != cend(); ++it) {
                it->first.print();
                PRINT "=> " BYLW AND it->second;
                PRINT CLR " = " BGRN AND it->second * market[it->first] AND CLR ENDL;
        }
}
