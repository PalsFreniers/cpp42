#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <sys/cdefs.h>

template<class Target, class Source>
Target narrow_cast(Source v)
{
   __auto_type r = static_cast<Target>(v); // convert the value to the target type
   if (static_cast<Source>(r)!=v)
      throw std::runtime_error("narrow_cast<>() failed");
   return r;
}

bool isnum(std::string s) {
        for(__auto_type it = s.begin(); it != s.end(); it++) {
                if(!std::isdigit(*it)) return false;
        }
        return true;
}

class ScalarConverter {
public:
        static void convert(std::string s) {
                char *c;
                double d = std::strtod(s.c_str(), &c);
                if(!(std::string(c) == "" || std::string(c) == "f") && !isnum(std::string(c))) {
                        std::cout << "bad conversion of " << s << std::endl;
                        return;
                }
                try {
                        if(std::isnan(d) || std::isinf(d)) std::cout << "char: impossible\nint: impossible" << std::endl;
                        else if(std::isprint(narrow_cast<char>(static_cast<long>(d)))) std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
                        else std::cout << "char: Non displayable" << std::endl;
                } catch(...) {
                        std::cout << "char: overflowed" << std::endl;
                }
                try {
                        if(!(std::isnan(d) || std::isinf(d))) std::cout << "int: " << narrow_cast<int>(static_cast<long>(d)) << std::endl;
                } catch(...) {
                        std::cout << "overflowed" << std::endl;
                }
                try {
                        std::cout << "float: " << narrow_cast<float>(d);
                        if(static_cast<float>(d) - static_cast<int>(d) == 0) std::cout << ".0";
                        std::cout << "f" << std::endl;
                } catch(...) {
                        std::cout << "overflowed" << std::endl;
                }
                if(std::string(c) == "" || std::string(c) == "f") {
                        std::cout << "double: " << static_cast<float>(d);
                        if(d - static_cast<int>(d) == 0) std::cout << ".0";
                        std::cout << std::endl;
                } else std::cout << "double: overflowed" << std::endl;
        }
private:
        ScalarConverter() {}
        ScalarConverter(__attribute_maybe_unused__ ScalarConverter &other) {}
        ~ScalarConverter() {}
        ScalarConverter &operator=(__attribute_maybe_unused__ ScalarConverter &other) { return *this; }
};

int main(int c, char *args[]) {
        if(c != 2) return 1;
        ScalarConverter::convert(args[1]);
}
