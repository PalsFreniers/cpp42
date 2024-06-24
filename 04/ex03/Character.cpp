#include "Character.hpp"
#include "utils.hpp"

Character::Character() : _name("john doe"), _trashCapacity(10), _trashLen(0), _trash(new AMateria *[10]) {
        _inv[0] = 0;
        _inv[1] = 0;
        _inv[2] = 0;
        _inv[3] = 0;
}

Character::Character(std::string name) : _name(name), _trashCapacity(10), _trashLen(0), _trash(new AMateria *[10]) {
        _inv[0] = 0;
        _inv[1] = 0;
        _inv[2] = 0;
        _inv[3] = 0;
}

Character::~Character() {
        for(int i = 0; i < 4; i++) if(_inv[i] != nullptr) delete _inv[i]; 
        trashOut();
        delete[] _trash;
}

Character::Character(const Character &other) {
        *this = other;
        _trash = new AMateria *[10];
        _trashCapacity = 10;
        _trashLen = 0;
}

Character &Character::operator=(const Character &other) {
        for(int i = 0; i < 4; i++) if(_inv[i] != nullptr) delete _inv[i]; 
        for(int i = 0; i < 4; i++) _inv[i] = other._inv[i]->clone();
        trashOut();
        return *this;
}

void Character::trashOut() {
        for(int i = 0; i < _trashLen; i++) delete _trash[i];
        _trashLen = 0;
}

void Character::trashMore() {
        _trashCapacity *= 2;
        AMateria **tmp = new AMateria *[_trashCapacity];
        for(int i = 0; i < _trashLen; i++) {
                tmp[i] = _trash[i];
        }
        delete[] _trash;
        _trash = tmp;
}

std::string const &Character::getName() const {
        return _name;
}

void Character::equip(AMateria *m) {
        for(int i = 0; i < 4; i++) {
                if(_inv[i] == nullptr) {
                        _inv[i] = m;
                        break;
                }
        }
}

void Character::unequip(int idx) {
        if(idx < 0 || idx >= 4) return;
        if(_inv[idx] == nullptr) return;
        if(_trashLen == _trashCapacity) trashMore();
        _trash[_trashLen++] = _inv[idx];
        _inv[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
        if(idx < 0 || idx >= 4) return;
        if(_inv[idx] == nullptr) return;
        _inv[idx]->use(target);
}
