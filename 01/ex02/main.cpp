#include <iostream>
#include <string>

int main() {
        std::string str = "HI THIS IS BRAIN";
        std::string *stringPTR = &str;
        std::string &stringREF = str;
        std::cout << "str addr: " << &str << std::endl;
        std::cout << "stringPTR addr: " << stringPTR << std::endl;
        std::cout << "stringREF addr: " << &stringREF << std::endl;


        std::cout << "str value: " << str << std::endl;
        std::cout << "stringPTR value: " << *stringPTR << std::endl;
        std::cout << "stringREF value: " << stringREF << std::endl;
}
