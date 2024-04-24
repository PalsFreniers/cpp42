#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _bits(0) {
        std::cout << "Default constructor called" << std::endl;
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
        std::cout << "getRawBits member function called" << std::endl;
        return _bits;
}

void Fixed::setRawBits(int raw) {
        std::cout << "setRawBits member function called" << std::endl;
        _bits = raw;
}
