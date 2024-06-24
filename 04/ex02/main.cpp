#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define ARRAY_LEN(x) (sizeof(x)/sizeof((x)[0]))

template<typename t, typename b>
bool instanceof(b obj) {
        if(dynamic_cast<t>(obj) == nullptr) return false;
        return true;
}

int main() {
//         AAnimal a = AAnimal(); // uncomment to have a compilation error
        AAnimal *table[] = {
                new Dog(), new Dog(), new Dog(),
                new Cat(), new Cat(), new Cat(),
        };

        try {
                for(int i = 0; i < 120; i++) table[1]->setIdea("test", i);
        } catch (std::exception &e) {
                std::cout << e.what() << std::endl;
        }

        AAnimal *b = reinterpret_cast<AAnimal *>(nullptr);
        if(instanceof<Dog *>(table[1])) {
                b = new Dog(*dynamic_cast<Dog *>(table[1]));
        }

        for(int i = 0; i < static_cast<int>(ARRAY_LEN(table)); i++) delete table[i];

        std::cout << b->getIdea(5) << std::endl;

        delete b;
}
