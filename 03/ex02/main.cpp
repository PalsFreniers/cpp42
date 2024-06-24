#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

void attack(ClapTrap &a, ClapTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

void attack(ClapTrap &a, FragTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

void attack(FragTrap &a, ClapTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

void attack(FragTrap &a, FragTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

int main() {
        FragTrap a("Malik");
        FragTrap b;
        FragTrap c(a);
        ClapTrap d("Mike");
        b = a;

        attack(d, b);
        attack(b, a);
        b.highFivesGuys();
        for(int i = 0; i < 101; i++) attack(c, b);
        attack(b, c);

        for(int i = 0; i < 101; i++) a.highFivesGuys();
}
