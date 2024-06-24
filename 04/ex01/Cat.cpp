#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
        std::cout << "Cat constructed" << std::endl;
        b = new Brain();
}

Cat::~Cat() {
        std::cout << "Cat destroyed" << std::endl;
        delete b;
}

Cat::Cat(const Cat &other) {
        std::cout << "Cat copied" << std::endl;
        b = new Brain();
        *this = other;
}

Cat &Cat::operator=(const Cat &other) {
        type = other.type;
        *b = *other.b;
        return *this;
}

void Cat::makeSound() {
        std::cout << "meow meow!" <<std::endl;
}

void Cat::setIdea(std::string idea, int id) {
        b->setIdea(idea, id);
}

std::string Cat::getIdea(int id) {
        return b->getIdea(id);
}
