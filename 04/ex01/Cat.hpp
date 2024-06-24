#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal {
public:
        Cat();
        virtual ~Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);

        virtual void makeSound();
        virtual void setIdea(std::string idea, int id);
        virtual std::string getIdea(int id);
private:
        Brain *b;
};
