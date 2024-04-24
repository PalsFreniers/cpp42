#include "Fixed.hpp"
#include <iostream>

int main( void ) {
        Fixed a(10);
        Fixed b(20);
        std::cout << "10 < 20 : " << std::boolalpha << (a < b) << std::noboolalpha << std::endl;
        std::cout << "10 > 20 : " << std::boolalpha << (a > b) << std::noboolalpha << std::endl;
        std::cout << "10 <= 20 : " << std::boolalpha << (a <= b) << std::noboolalpha << std::endl;
        std::cout << "10 >= 20 : " << std::boolalpha << (a >= b) << std::noboolalpha << std::endl;
        std::cout << "10 == 20 : " << std::boolalpha << (a == b) << std::noboolalpha << std::endl;
        std::cout << "10 != 20 : " << std::boolalpha << (a != b) << std::noboolalpha << std::endl;
        std::cout << "10 + 20 : " << (a + b) << std::endl;
        std::cout << "10 - 20 : " << (a - b) << std::endl;
        std::cout << "10 * 20 : " << (a * b) << std::endl;
        std::cout << "10 / 20 : " << (a / b) << std::endl;
        std::cout << "10++ : " << (a++) << " then become : " << a << std::endl;
        std::cout << "++10 : " << (++a) << " then become : " << a << std::endl;
        std::cout << "20-- : " << (b--) << " then become : " << b << std::endl;
        std::cout << "--20 : " << (--b) << " then become : " << b << std::endl;
        const Fixed c(Fixed(25) + Fixed(25));
        std::cout << "min(10, 20) : " << Fixed::min(a, b) << std::endl;
        std::cout << "max(10, 20) : " << Fixed::max(a, b) << std::endl;
        std::cout << "min(20, 50) : " << Fixed::min(b, c) << std::endl;
        std::cout << "max(20, 50) : " << Fixed::max(b, c) << std::endl;
        return 0;
}
