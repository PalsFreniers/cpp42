#include <exception>
#include <iostream>
#include <string>

#define extends :
#define foreach(name, data) for(__typeof__((data).begin()) name = (data).begin(); name != (data).end(); name++)

class NotEnoughArgumentException extends public std::exception {
public:
        NotEnoughArgumentException() {}
        const char *what() const throw() { return "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; }
};

namespace lambdas {
        void l1(const int count, const char *const args[]) {
                if(count < 2) throw NotEnoughArgumentException();
                for(int i = 1; i < count; i++) {
                        std::string str = args[i];
                        foreach(it, str) std::cout << static_cast<char>(std::toupper(*it));
                }
                std::cout << std::endl;
        }
}

int main(const int count, const char *const args[])
{
        try {
                lambdas::l1(count, args);
        } catch(NotEnoughArgumentException e) {
                std::cout << e.what() << std::endl;
        }
        return 0;
}
