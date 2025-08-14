#include "../inc/utils.h"

date extractDate(std::string &line, char c) {
        char *end;
        errno = 0;
        auto year = strtol(line.c_str(), &end, 10);
        if(errno == ERANGE || *end != '-') throw std::out_of_range("Invalid Year");
        auto month = strtol(&line.at(5), &end, 10);
        if(errno == ERANGE || *end != '-') throw std::out_of_range("Invalid Month");
        auto day = strtol(&line.at(8), &end, 10);
        if(errno == ERANGE || *end != c) throw std::out_of_range("Invalid Day");
        return date(year, month, day);
}

float extractRate(std::string &line, int start) {
        char *end;
        errno = 0;
        auto rate = strtof(&line.at(start), &end);
        if(errno == ERANGE) throw std::overflow_error("Rate is too big");
        if(*end != '\0') throw std::logic_error("Invalid Line");
        if(rate < 0) throw std::domain_error("Rate cannot be negative");
        return rate;
}
