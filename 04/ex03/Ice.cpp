#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {

}

Ice::~Ice() {

}

Ice::Ice(const Ice &other) {
        *this = other;
}

Ice &Ice::operator=(const Ice &other) {
        _type = other._type;
        return *this;
}

Ice *Ice::clone() const {
        return new Ice(*this);
}

void Ice::use(ICharacter &target) {
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
