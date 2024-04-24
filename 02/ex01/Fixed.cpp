#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _bits(0) {
        std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) {
        std::cout << "Int constructor called" << std::endl;
        _bits = integer << fractionalBits;
}

Fixed::Fixed(const float floating) {
        std::cout << "Float constructor called" << std::endl;
        _bits = (int)roundf(floating * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
        std::cout << "Copy constructor called" << std::endl;
        *this = other;
}

Fixed::~Fixed() {
        std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
        std::cout << "Copy assignment operator called" << std::endl;
        _bits = other._bits;
        return *this;
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
