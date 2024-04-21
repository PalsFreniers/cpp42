#pragma once

#include <string>

class Weapon {
public:
        Weapon();
        ~Weapon();
        Weapon(std::string typ);
        Weapon(const Weapon &other);
        Weapon &operator=(const Weapon &other);

        std::string getType();
        void setType(std::string typ);
private:
        std::string type;
};
