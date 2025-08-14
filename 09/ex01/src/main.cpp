#include "../inc/RPN.h"

int main(int argc, char *argv[]) {
        auto arg = std::string("0");
        if(argc > 1) arg = argv[1];
        auto calculator = RPN();
        try {
                PRINT BCYN "Now calculating: " BYLW AND arg AND CLR ENDL;
                calculator.calculate(argv[1]);
        } catch (std::exception &e) {
                ERROR BRED AND e.what() AND CLR ENDL;
                return 1;
        }
}
