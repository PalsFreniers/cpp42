#include "Zombie.hpp"
#include <iostream>

int main() {
        {
                Zombie *hrd = zombieHorde(12, "Nathan");
                for(int i = 0; i < 12; i++) {
                        std::cout << "Zombie " << i + 1 << " from horde Annouces:" << std::endl << '\t';
                        hrd[i].announce();
                }
                delete[] hrd;
        }
        {
                Zombie *hrd = zombieHorde(5, "Samuel");
                for(int i = 0; i < 5; i++) {
                        std::cout << "Zombie " << i + 1 << " from horde Annouces:" << std::endl << '\t';
                        hrd[i].announce();
                }
                delete[] hrd;
        }
        return 0;
}
