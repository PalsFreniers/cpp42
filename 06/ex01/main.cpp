#include <iostream>
#include <stdint.h>

struct Data {
        int a;
        int b;
        float c;
        union {
                int xi;
                float xf;
        };
};

class Serializer {
public:
        static uintptr_t serialize(Data *ptr) {
                return reinterpret_cast<uintptr_t>(ptr);
        }

        static Data *deserialize(uintptr_t raw) {
                return reinterpret_cast<Data *>(raw);
        }
private:
        Serializer() {}
        Serializer(__attribute_maybe_unused__ Serializer &other) {}
        ~Serializer() {}
        Serializer &operator=(__attribute_maybe_unused__ Serializer &other) { return *this; }
};

int main() {
        Data d = (Data){1, 2, 3.5f, {25}};
        if(Serializer::deserialize(Serializer::serialize(&d)) == &d) std::cout << "yes" << std::endl;
        else std::cout << "no" << std::endl;
}
