#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
        std::cout << "Cat constructed" << std::endl;
}

Cat::~Cat() {
        std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(const Cat &other) {
        std::cout << "Cat copied" << std::endl;
        *this = other;
}

Cat &Cat::operator=(const Cat &other) {
        type = other.type;
        return *this;
}

void Cat::makeSound() {
        std::cout << "meow meow!" <<std::endl;
}
