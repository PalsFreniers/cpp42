#include <iostream>
#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
        std::cout << "Dog constructed" << std::endl;
        b = new Brain();
}

Dog::~Dog() {
        std::cout << "Dog destroyed" << std::endl;
        delete b;
}

Dog::Dog(const Dog &other) {
        std::cout << "Dog copied" << std::endl;
        b = new Brain();
        *this = other;
}

Dog &Dog::operator=(const Dog &other) {
        type = other.type;
        *b = *other.b;
        return *this;
}

void Dog::makeSound() {
        std::cout << "bark bark!" <<std::endl;
}

void Dog::setIdea(std::string idea, int id) {
        b->setIdea(idea, id);
}

std::string Dog::getIdea(int id) {
        return b->getIdea(id);
}
