#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _bits(0) {
}

Fixed::Fixed(const int integer) {
        _bits = integer << fractionalBits;
}

Fixed::Fixed(const float floating) {
        _bits = (int)roundf(floating * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
        *this = other;
}

Fixed::~Fixed() {
}

Fixed &Fixed::operator=(const Fixed &other) {
        _bits = other._bits;
        return *this;
}

bool Fixed::operator<(const Fixed &other) {
       return toFloat() < other.toFloat(); 
}
        
bool Fixed::operator>(const Fixed &other) {
       return toFloat() > other.toFloat(); 
}
        
bool Fixed::operator<=(const Fixed &other) {
       return toFloat() <= other.toFloat(); 
}

bool Fixed::operator>=(const Fixed &other) {
       return toFloat() >= other.toFloat(); 
}

bool Fixed::operator==(const Fixed &other) {
       return _bits == other._bits; 
}

bool Fixed::operator!=(const Fixed &other) {
       return _bits != other._bits; 
}

Fixed Fixed::operator+(const Fixed &other) {
        return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) {
        return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) {
        return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) {
        if(Fixed(0) == other) return 0;
        return Fixed(toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
        _bits++;
        return *this;
}

Fixed Fixed::operator++(int) {
        Fixed old = *this;
        operator++();
        return old;
}

Fixed &Fixed::operator--() {
        _bits--;
        return *this;
}

Fixed Fixed::operator--(int) {
        Fixed old = *this;
        operator--();
        return old;
}



int Fixed::getRawBits() {
        return _bits;
}

void Fixed::setRawBits(int raw) {
        _bits = raw;
}

float Fixed::toFloat() const {
        return (float)_bits / (1 << fractionalBits);
}

int Fixed::toInt() const {
        return _bits >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &nb) {
        out << nb.toFloat();
        return out;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
        return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
        return a >= b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
        return a.toFloat() < b.toFloat() ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
        return a.toFloat() >= b.toFloat() ? a : b;
}
