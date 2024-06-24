#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

void attack(ClapTrap &a, ClapTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

void attack(ClapTrap &a, DiamondTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

void attack(DiamondTrap &a, ClapTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

void attack(DiamondTrap &a, DiamondTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

int main() {
        DiamondTrap a("Malik");
        DiamondTrap b;
        DiamondTrap c(a);
        ClapTrap d("Mike");
        b = a;

        attack(d, b);
        attack(b, a);
        b.highFivesGuys();
        for(int i = 0; i < 51; i++) attack(c, b);
        attack(b, c);

        for(int i = 0; i < 51; i++) a.highFivesGuys();
        a.whoAmI();
        b.whoAmI();
        DiamondTrap test("Michael");
        test.attack("hell");
        test.beRepaired(10);
        test.takeDamage(20);
        test.guardGate();
        test.highFivesGuys();
        test.whoAmI();
}
