#pragma once

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public virtual ClapTrap {
public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);

        void attack(const std::string &target);
        void guardGate();
};
