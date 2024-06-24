#pragma once

#include "AMateria.hpp"
#include <string>

class Character : public ICharacter {
public:
        Character();
        virtual ~Character();
        Character(std::string name);
        Character(const Character &other);
        Character &operator=(const Character &other);

        virtual std::string const &getName() const;
        virtual void equip(AMateria *m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter &target);
        void trashOut();
        void trashMore();
private:
        AMateria *_inv[4];
        std::string _name;
        int _trashCapacity;
        int _trashLen;
        AMateria **_trash;
};
