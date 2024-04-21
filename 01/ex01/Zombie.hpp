#pragma once

#include <string>

class Zombie {
public:
        Zombie();
        ~Zombie();
        Zombie(const Zombie &other);
        Zombie(std::string name);
        Zombie &operator=(const Zombie &other);

        void announce();
private:
        std::string name;
};

Zombie *zombieHorde(int nb, std::string name);
