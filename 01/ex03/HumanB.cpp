#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _weapon(0), _name(name) {}

HumanB::~HumanB() {

}

void HumanB::attack() {
        if(_weapon) std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
        else std::cout << _name << " attacks with bare fists" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
        _weapon = &weapon;
}
