#include "ClapTrap.hpp"

void attack(ClapTrap &a, ClapTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

int main() {
        ClapTrap a("Malik");
        ClapTrap b;
        ClapTrap c(a);
        b = a;

        attack(a, b);
        a.takeDamage(5);
        a.beRepaired(20);
        c.takeDamage(100);
}
