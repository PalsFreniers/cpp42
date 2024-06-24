#include <iostream>
#include "Animal.hpp"

#define UNUSED(x) (void)(x)

Animal::Animal() : type("") {
        std::cout << "Animal constructed" << std::endl;
}

Animal::~Animal() {
        std::cout << "Animal destroyed" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
        std::cout << "Animal " << type << " constructed" << std::endl;
}

Animal::Animal(const Animal &other) {
        std::cout << "Animal copied" << std::endl;
        *this = other;
}

Animal &Animal::operator=(const Animal &other) {
        type = other.type;
        return *this;
}

void Animal::makeSound() {
        std::cout << "graou... maybe!" <<std::endl;
}

std::string Animal::getType() {
        return type;
}

void Animal::setIdea(std::string idea, int id) {
        UNUSED(idea);
        UNUSED(id);
        throw NoBrainException();
}

std::string Animal::getIdea(int id) {
        UNUSED(id);
        throw NoBrainException();
}

const char *Animal::NoBrainException::what() const throw() {
        return "this Animal Has no brain";
}
