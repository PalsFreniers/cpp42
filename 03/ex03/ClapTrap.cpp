#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("john doe"), _hp(10), _ep(10), _ap(0) {
        std::cout << "created unknown ClapTrap" << std::endl;
}

ClapTrap::~ClapTrap() {
        std::cout << "destroyed ClapTrap : " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ap(0) {
        std::cout << "created ClapTrap : " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
        std::cout << "copied ClapTrap : " << other._name << std::endl;
        *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
        _name = other._name;
        _hp = other._hp;
        _ep = other._ep;
        _ap = other._ap;
        return *this;
}

void ClapTrap::attack(const std::string &target) {
        if(_hp == 0)std::cout << "ClapTrap " << _name << " is dead and can not attack!" << std::endl;
        else if(_ep == 0) std::cout << "ClapTrap " << _name << " does not have anymore energy to attack!" << std::endl;
        else {
                std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _ap << " points of damage!" << std::endl;
                _ep--;
        }
}

void ClapTrap::takeDamage(unsigned int amount) {
        if(_hp == 0)std::cout << "ClapTrap " << _name << " is dead and can not take damage!" << std::endl;
        else {
                std::cout << "ClapTrap " << _name << " took " << amount << " of damage!" << std::endl;
                _hp = amount >= _hp ? 0 : _hp - amount;
                if(_hp == 0) std::cout << "ClapTrap " << _name << " died!" << std::endl;
        }
}

void ClapTrap::beRepaired(unsigned int amount) {
        if(_hp == 0)std::cout << "ClapTrap " << _name << " is dead and can not revive!" << std::endl;
        else if(_ep == 0) std::cout << "ClapTrap " << _name << " does not have anymore energy to regain health!" << std::endl;
        else {
                std::cout << "ClapTrap " << _name << " gained " << amount << " of health!" << std::endl;
                _hp += amount;
                _ep--;
        }
}

unsigned int ClapTrap::getAP() {
        return _ap;
}

std::string ClapTrap::getName() {
        return _name;
}
