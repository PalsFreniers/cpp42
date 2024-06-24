#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal {
public:
        Dog();
        virtual ~Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);

        virtual void makeSound();
        virtual void setIdea(std::string idea, int id);
        virtual std::string getIdea(int id);
private:
        Brain *b;
};
