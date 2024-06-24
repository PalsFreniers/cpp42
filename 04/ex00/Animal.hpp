#pragma once

#include <string>

class Animal {
public:
        Animal();
        virtual ~Animal();
        Animal(std::string type);
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);

        virtual void makeSound();
        std::string getType();
protected:
        std::string type;
};
