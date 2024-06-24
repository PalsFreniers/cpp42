#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("John Doe"), _name(ClapTrap::_name + "_clap_name") {
        _hp = 100;
        _ep = 50;
        _ap = 30;
        std::cout << "DiamondTrap created" << std::endl;
}

DiamondTrap::~DiamondTrap() {
        std::cout << "DiamondTrap destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), _name(ClapTrap::_name + "_clap_name") {
        _hp = 100;
        _ep = 50;
        _ap = 30;
        std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
        std::cout << "copied DiamondTrap : " << other._name << std::endl;
        *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
        _name = other._name;
        ClapTrap::_name = other.ClapTrap::_name;
        _hp = other._hp;
        _ep = other._ep;
        _ap = other._ap;
        return *this;
}

void DiamondTrap::whoAmI() {
        if(_hp == 0) std::cout << "This dead DiamondTrap was known as " << ClapTrap::_name << "(aka: " << _name << ")" << std::endl;
        else if(_ep == 0) std::cout << "This tired DiamondTrap is known as " << ClapTrap::_name << "(also: " << _name << ")" << std::endl;
        else std::cout << "I am " << _name << " also known as " << ClapTrap::_name << std::endl;
}
