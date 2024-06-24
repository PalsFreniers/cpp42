#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
        {
                Cat a;
                Dog b;
                Animal c;
                
                a.makeSound();
                b.makeSound();
                c.makeSound();
        }
        {
                Animal *a = new Cat();
                Animal *b = new Dog();
                Animal *c = new Animal();
                
                a->makeSound();
                b->makeSound();
                c->makeSound();
                delete a;
                delete b;
                delete c;
        }
        {
                WrongCat a;
                WrongAnimal c;
                
                a.makeSound();
                c.makeSound();
        }
        {
                WrongAnimal *a = new WrongCat();
                WrongAnimal *c = new WrongAnimal();
               
                a->makeSound();
                c->makeSound();
                delete a;
                delete c;
        }
}
