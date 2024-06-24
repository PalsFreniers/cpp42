#pragma once

#include "Animal.hpp"
#include <string>

class Dog : public Animal {
public:
        Dog();
        virtual ~Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);

        virtual void makeSound();
};
