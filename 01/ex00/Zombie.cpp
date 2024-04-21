#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("Foo") {}

Zombie::~Zombie() {
        std::cout << "Destroyed: " << name << std::endl;
}

Zombie::Zombie(const Zombie &other) {
        *this = other;
}

Zombie::Zombie(std::string name) : name(name) {}

Zombie &Zombie::operator=(const Zombie &other) {
        name = other.name;
        return *this;
}

void Zombie::announce() {
        std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
