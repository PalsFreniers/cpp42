#pragma once

#include <iostream>

class Fixed {
public:
        Fixed();
        Fixed(const int integer);
        Fixed(const float floating);
        Fixed(const Fixed &other);
        ~Fixed();
        Fixed &operator=(const Fixed &other);

        int getRawBits();
        void setRawBits(int raw);
        float toFloat() const;
        int toInt() const;
private:
        int _bits;
        static const int fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &nb);
