#pragma once

#include <string>
#include <exception>

class Animal {
public:
        Animal();
        virtual ~Animal();
        Animal(std::string type);
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);

        virtual void makeSound();
        virtual void setIdea(std::string idea, int id);
        virtual std::string getIdea(int id);
        std::string getType();
        
        class NoBrainException {
        public:
                virtual const char *what() const throw();
        };
protected:
        std::string type;
};

#define nullptr ((void *)0)
