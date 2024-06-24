#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public AAnimal {
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
