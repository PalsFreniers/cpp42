#include "../inc/RPN.h"

int main(int argc, char *argv[]) {
        if(argc != 2) ERROR BRED AND "unable to parse RPN program ''" AND CLR ENDL;
        RPN calculator;
        try {
                PRINT BCYN "Now calculating: " BYLW AND argv[1] AND CLR ENDL;
                calculator.calculate(argv[1]);
        } catch (std::exception &e) {
                ERROR BRED AND e.what() AND CLR ENDL;
                return (1);
        }
}
