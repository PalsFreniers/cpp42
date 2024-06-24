#pragma once

#include "ICharacter.hpp"
#include <string>

class AMateria {
public:
        AMateria();
        AMateria(std::string const &type);
        virtual ~AMateria();
        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);

        std::string const &getType() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
protected:
        std::string _type;
};
