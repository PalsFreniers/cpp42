#pragma once

#include <string>

class WrongAnimal {
public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);

        void makeSound();
        std::string getType();
protected:
        std::string type;
};
