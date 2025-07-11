#include "../inc/Date.h"

const date date::dateNull = date();

date::date() {
        year = 0;
        month = 0;
        day = 0;
}

static bool isValidDate(uint month, uint day) {
        if (month < 1 || month > 12) return false;
        else if (month == 2) { if (day < 1 || day > 29) return false; }
        else if (month == 4 || month == 6 || month == 9 || month == 11) { if (day < 1 || day > 30) return false; }
        else if (day < 1 || day > 31) return false;
        return true;
}

date::date(uint year, uint month, uint day) {
        year = year;
        month = month;
        day = day;
        if(!isValidDate(month, day)) throw std::domain_error("Invalid date");
}

bool date::operator==(const date& rhs) const {
        if(year != rhs.year) return false;
        if(month != rhs.month) return false;
        if(day != rhs.day) return false;
        return true;
}

bool date::operator!=(const date& rhs) const {
        if(year != rhs.year) return true;
        if(month != rhs.month) return true;
        if(day != rhs.day) return true;
        return false;
}

bool date::operator>(const date& rhs) const {
        if(year != rhs.year) return year > rhs.year;
        if(month != rhs.month) return month > rhs.month;
        if(day != rhs.day) return day > rhs.day;
        return false;
}

bool date::operator>=(const date& rhs) const {
        if(year != rhs.year) return year > rhs.year;
        if(month != rhs.month) return month > rhs.month;
        if(day != rhs.day) return day > rhs.day;
        return true;
}

bool date::operator<(const date& rhs) const {
        if(year != rhs.year) return year < rhs.year;
        if(month != rhs.month) return month < rhs.month;
        if(day != rhs.day) return day < rhs.day;
        return false;
}

bool date::operator<=(const date& rhs) const {
        if(year != rhs.year) return year < rhs.year;
        if(month != rhs.month) return month < rhs.month;
        if(day != rhs.day) return day < rhs.day;
        return true;
}

void date::print() const {
        PRINT BBLK " [ " AND year AND "-";
        PRINT std::setfill('0') AND std::setw(2) AND month;
        std::flush(std::cout);
        PRINT "-";
        PRINT std::setfill('0') AND std::setw(2) AND day;
        std::flush(std::cout);
        PRINT " ] " CLR;
}
