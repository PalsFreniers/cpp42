#pragma once

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria {
public:
        Ice();
        virtual ~Ice();
        Ice(const Ice &other);
        Ice &operator=(const Ice &other);

        virtual Ice *clone() const;
        virtual void use(ICharacter &target);
};
