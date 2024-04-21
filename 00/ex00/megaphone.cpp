#include <iostream>
#include <string>

namespace lambdas {
        void l1(const int count, const char *const args[]) {
                for(int i = 1; i < count; i++) {
                        std::string str = args[i];
                                for(std::string::iterator it = str.begin(); it != str.end(); it++) std::cout << static_cast<char>(std::toupper(*it));
                }
        }
}

int main(const int count, const char *const args[])
{
        count > 2 ? lambdas::l1(count, args) : static_cast<void>(std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *");
        std::cout << '\n';
        return 0;
}
