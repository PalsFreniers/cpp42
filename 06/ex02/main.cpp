#include <cstdlib>
#include <ctime>
#include <iostream>

#define nullptr 0

template<typename type, typename value>
bool instanceofp(value data) {
        return dynamic_cast<type *>(data) != nullptr;
}

template<typename type, typename value>
bool instanceof(value &data) {
        try  {
                void *f = nullptr;
                value &unused = (value &)f;
                unused = dynamic_cast<type &>(data);
                (void)unused;
                return true;
        } catch(...) {
                return false;
        }
}

class Base {
public:
        Base() {}
        Base(Base &other) {(void)other;}
        virtual ~Base() {}
        Base &operator=(Base &other) {(void)other; return *this;}
private:
};

class A : public Base {
public:
        A() {}
        A(A &other) {(void)other;}
        virtual ~A() {}
        A &operator=(A &other) {(void)other; return *this;}
private:
};

class B : public Base {
public:
        B() {}
        B(B &other) {(void)other;}
        virtual ~B() {}
        B &operator=(B &other) {(void)other; return *this;}
private:
};

class C : public Base {
public:
        C() {}
        C(C &other) {(void)other;}
        virtual ~C() {}
        C &operator=(C &other) {(void)other; return *this;}
private:
};

Base *generate() {
        int r = std::rand() % 3;
        return r == 0 ? dynamic_cast<Base *>(new A()) :
               r == 1 ? dynamic_cast<Base *>(new B()) : dynamic_cast<Base *>(new C());
}

void identify(Base *ptr) {
        if(instanceofp<A>(ptr)) std::cout << "A" << std::endl;
        else if(instanceofp<B>(ptr)) std::cout << "B" << std::endl;
        else if(instanceofp<C>(ptr)) std::cout << "C" << std::endl;
        else std::cout << "UKNOWN" << std::endl;
}

void identify(Base &ref) {
        if(instanceof<A>(ref)) std::cout << "A" << std::endl;
        else if(instanceof<B>(ref)) std::cout << "B" << std::endl;
        else if(instanceof<C>(ref)) std::cout << "C" << std::endl;
        else std::cout << "UKNOWN" << std::endl;
}

int main() {
        std::srand(std::time(NULL));
        for (int i = 0; i < 100; i++) {
                Base *base = generate();
                identify(base);
                identify(*base);
                delete base;
        }
}
