#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") {
        std::cout << "WrongAnimal constructed" << std::endl;
}

WrongAnimal::~WrongAnimal() {
        std::cout << "WrongAnimal destroyed" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
        std::cout << "WrongAnimal " << type << " constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
        std::cout << "WrongAnimal copied" << std::endl;
        *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
        type = other.type;
        return *this;
}

void WrongAnimal::makeSound() {
        std::cout << "graou... maybe!" <<std::endl;
}

std::string WrongAnimal::getType() {
        return type;
}
