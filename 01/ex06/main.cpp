#include "Harl.hpp"
#include <iostream>

int main(int c, char *args[]) {
        if(c < 2 || c > 2) {
                std::cerr << "Error Harl filter only take 1 argument" << std::endl;
                return 1;
        }
        Harl h;
        h.complain(args[1]);
        return 0;
}
