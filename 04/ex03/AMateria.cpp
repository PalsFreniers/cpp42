#include "AMateria.hpp"
#include <iostream>
#define UNUSED(x) ((void)(x))

AMateria::AMateria() : _type("None") {

}

AMateria::AMateria(std::string const & type) : _type(type) {

}

AMateria::~AMateria() {

}

AMateria::AMateria(const AMateria &other) {
        *this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
        _type = other._type;
        return *this;
}

std::string const &AMateria::getType() const {
        return _type;
}

void AMateria::use(ICharacter& target) {
        UNUSED(target);
        std::cout << "Nothing Happend!" << std::endl;
}
