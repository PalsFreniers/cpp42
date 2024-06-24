#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
        std::cout << "Dog constructed" << std::endl;
}

Dog::~Dog() {
        std::cout << "Dog destroyed" << std::endl;
}

Dog::Dog(const Dog &other) {
        std::cout << "Dog copied" << std::endl;
        *this = other;
}

Dog &Dog::operator=(const Dog &other) {
        type = other.type;
        return *this;
}

void Dog::makeSound() {
        std::cout << "bark bark!" <<std::endl;
}
