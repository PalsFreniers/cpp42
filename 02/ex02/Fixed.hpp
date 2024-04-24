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

        bool operator<(const Fixed &other);
        bool operator>(const Fixed &other);
        bool operator<=(const Fixed &other);
        bool operator>=(const Fixed &other);
        bool operator==(const Fixed &other);
        bool operator!=(const Fixed &other);
        Fixed operator+(const Fixed &other);
        Fixed operator-(const Fixed &other);
        Fixed operator*(const Fixed &other);
        Fixed operator/(const Fixed &other);
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        int getRawBits();
        void setRawBits(int raw);
        float toFloat() const;
        int toInt() const;

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
private:
        int _bits;
        static const int fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &nb);
