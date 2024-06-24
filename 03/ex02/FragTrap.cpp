#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("john doe") {
        _hp = 100;
        _ep = 100;
        _ap = 30;
        std::cout << "created unknown FragTrap" << std::endl;
}

FragTrap::~FragTrap() {
        std::cout << "destroyed FragTrap : " << _name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
        _hp = 100;
        _ep = 100;
        _ap = 30;
        std::cout << "created FragTrap : " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
        std::cout << "copied FragTrap : " << other._name << std::endl;
        *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
        _name = other._name;
        _hp = other._hp;
        _ep = other._ep;
        _ap = other._ap;
        return *this;
}

void FragTrap::highFivesGuys() {
        if(_hp == 0)std::cout << "FragTrap " << _name << " is dead and can not High five!" << std::endl;
        else if(_ep == 0) std::cout << "FragTrap " << _name << " does not have anymore energy to High five!" << std::endl;
        else {
                std::cout << "FragTrap " << _name << " want to High five guys!" << std::endl;
                _ep--;
        }
}
