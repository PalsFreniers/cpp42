#include "Weapon.hpp"

Weapon::Weapon(): type("Random Type") {}

Weapon::~Weapon() {}

Weapon::Weapon(std::string typ) : type(typ) {}

Weapon::Weapon(const Weapon &other) {
        *this = other;
}

Weapon &Weapon::operator=(const Weapon &other) {
        type = other.type;
        return *this;
}

std::string Weapon::getType() {
        return type;
}

void Weapon::setType(std::string typ) {
        type = typ;
}
