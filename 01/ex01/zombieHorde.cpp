#include "Zombie.hpp"

Zombie *zombieHorde(int nb, std::string name) {
        Zombie *ret = new Zombie[nb];
        for(int i = 0; i < nb; i++) ret[i] = name;
        return ret;
}
