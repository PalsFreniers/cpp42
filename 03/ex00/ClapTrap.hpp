#pragma once

#include <string>

class ClapTrap {
public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        unsigned int getAP();
        std::string getName();
private:
        std::string _name;
        unsigned int _hp;
        unsigned int _ep;
        unsigned int _ap;
};
