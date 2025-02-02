#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {

}

Cure::~Cure() {

}

Cure::Cure(const Cure &other) {
        *this = other;
}

Cure &Cure::operator=(const Cure &other) {
        _type = other._type;
        return *this;
}

Cure *Cure::clone() const {
        return new Cure(*this);
}

void Cure::use(ICharacter &target) {
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
