#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public AAnimal {
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
