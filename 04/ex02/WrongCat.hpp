#pragma once

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {
public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat &other);
        WrongCat &operator=(const WrongCat &other);

        void makeSound();
};
