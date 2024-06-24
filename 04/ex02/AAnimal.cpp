#include <iostream>
#include "AAnimal.hpp"

#define UNUSED(x) (void)(x)

AAnimal::AAnimal() : type("") {
        std::cout << "AAnimal constructed" << std::endl;
}

AAnimal::~AAnimal() {
        std::cout << "AAnimal destroyed" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type) {
        std::cout << "AAnimal " << type << " constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
        std::cout << "AAnimal copied" << std::endl;
        *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
        type = other.type;
        return *this;
}

std::string AAnimal::getType() {
        return type;
}
