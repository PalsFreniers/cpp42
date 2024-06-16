#include "Zombie.hpp"
#include <iostream>

int main() {
        {
                std::cout << "creating using static then dynamic allocation" << std::endl;
                Zombie z1("Frank");
                Zombie *z2 = new Zombie("Marcel");
                z2->announce();
                z1.announce();
                delete z2;
        }
        {
                std::cout << "creating using static then dynamic allocation but using the exercise's functions" << std::endl;
                randomChump("Jacque");
                Zombie *z1 = newZombie("Jean-Marie");
                z1->announce();
                delete z1;
        }
        return 0;
}
