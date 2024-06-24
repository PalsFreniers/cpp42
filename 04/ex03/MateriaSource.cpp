#include "MateriaSource.hpp"
#include "utils.hpp"

MateriaSource::MateriaSource() {
        _inv[0] = 0;
        _inv[1] = 0;
        _inv[2] = 0;
        _inv[3] = 0;
}

MateriaSource::~MateriaSource() {
        for(int i = 0; i < 4; i++) delete _inv[i];
}

MateriaSource::MateriaSource(const MateriaSource &other) {
        *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
        for(int i = 0; i < 4; i++) _inv[i] = other._inv[i]->clone();
        return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
        for(int i = 0; i < 4; i++) {
                if(_inv[i] == nullptr) {
                        _inv[i] = materia;
                        break;
                }
        }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
        for(int i = 0; i < 4; i++) {
                if(_inv[i] != nullptr && _inv[i]->getType() == type) return _inv[i]->clone();
        }
        return 0;
}
