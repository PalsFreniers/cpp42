#pragma once

#include <string>
#include <exception>

class AAnimal {
public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal &other);
        AAnimal &operator=(const AAnimal &other);

        virtual void makeSound() = 0;
        virtual void setIdea(std::string idea, int id) = 0;
        virtual std::string getIdea(int id) = 0;
        std::string getType();
protected:
        std::string type;
};

#define nullptr ((void *)0)
