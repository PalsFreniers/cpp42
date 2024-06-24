#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
        std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::~WrongCat() {
        std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
        std::cout << "WrongCat copied" << std::endl;
        *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
        type = other.type;
        return *this;
}

void WrongCat::makeSound() {
        std::cout << "meow meow!" <<std::endl;
}
