#pragma once

#include "IMateriaSource.hpp"
#include <string>

class MateriaSource : public IMateriaSource {
public:
        MateriaSource();
        virtual ~MateriaSource();
        MateriaSource(const MateriaSource &source);
        MateriaSource &operator=(const MateriaSource &source);

        virtual void learnMateria(AMateria *materia);
        virtual AMateria *createMateria(std::string const &type);
private:
        AMateria *_inv[4];
};
