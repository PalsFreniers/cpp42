#pragma once

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "colors.h"
#include "printUtils.h"

typedef unsigned int uint;

class date {
public:
        date();
        date(uint year, uint month, uint day);
        static const date dateNull;
        bool operator==(const date &rhs) const;
        bool operator!=(const date &rhs) const;
        bool operator>(const date &rhs) const;
        bool operator>=(const date &rhs) const;
        bool operator<(const date &rhs) const;
        bool operator<=(const date &rhs) const;
        void print() const;
        uint year;
        uint month;
        uint day;
};
