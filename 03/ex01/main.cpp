#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void attack(ClapTrap &a, ClapTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

void attack(ClapTrap &a, ScavTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

void attack(ScavTrap &a, ClapTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

void attack(ScavTrap &a, ScavTrap &b) {
        a.attack(b.getName());
        b.takeDamage(a.getAP());
}

int main() {
        ScavTrap a("Malik");
        ScavTrap b;
        ScavTrap c(a);
        ClapTrap d("Mike");
        b = a;

        attack(d, b);
        attack(b, a);
        b.guardGate();
        for(int i = 0; i < 101; i++) attack(c, b);
        attack(b, c);

        for(int i = 0; i < 51; i++) b.guardGate();
}
