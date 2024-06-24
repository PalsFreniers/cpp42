#pragma once

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public virtual ClapTrap {
public:
        FragTrap();
        ~FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &other);
        FragTrap &operator=(const FragTrap &other);

        void highFivesGuys(void);
};
