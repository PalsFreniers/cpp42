#include "Zombie.hpp"

int main() {
        {
                Zombie z1("Frank");
                Zombie *z2 = new Zombie("Marcel");
                z2->announce();
                z1.announce();
                delete z2;
        }
        {
                randomChump("Jacque");
                Zombie *z1 = newZombie("Jean-Marie");
                z1->announce();
                delete z1;
        }
        return 0;
}
