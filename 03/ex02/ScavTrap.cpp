#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("john doe") {
        _hp = 100;
        _ep = 50;
        _ap = 20;
        std::cout << "created unknown ScavTrap" << std::endl;
}

ScavTrap::~ScavTrap() {
        std::cout << "destroyed ScavTrap : " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
        _hp = 100;
        _ep = 50;
        _ap = 20;
        std::cout << "created ScavTrap : " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
        std::cout << "copied ScavTrap : " << other._name << std::endl;
        *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
        _name = other._name;
        _hp = other._hp;
        _ep = other._ep;
        _ap = other._ap;
        return *this;
}

void ScavTrap::attack(const std::string &target) {
        if(_hp == 0)std::cout << "ScavTrap " << _name << " is dead and can not attack!" << std::endl;
        else if(_ep == 0) std::cout << "ScavTrap " << _name << " does not have anymore energy to attack!" << std::endl;
        else {
                std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _ap << " points of damage!" << std::endl;
                _ep--;
        }
}

void ScavTrap::guardGate() {
        if(_hp == 0)std::cout << "ScavTrap " << _name << " is dead and can not use gate keeper mode!" << std::endl;
        else if(_ep == 0) std::cout << "ScavTrap " << _name << " does not have anymore energy to use gate keeper mode!" << std::endl;
        else {
                std::cout << "ScavTrap " << _name << " is now in gate keeper mode!" << std::endl;
                _ep--;
        }
}
