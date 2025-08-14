#include <iostream>
#include "../inc/colors.h"
#include "../inc/printUtils.h"
#include "../inc/StockMarket.h"
#include "../inc/BitcoinExchange.h"

int main(int argc, char *argv[]) {
        if(argc != 2) ERROR BRED AND "no input file sspecified" AND CLR ENDL;
        try {
                auto market = StockMarket();
                auto history = BitcoinExchange();
                history.loadFile(argv[1]);
                history.printValue(market);
        } catch(std::exception &e) {
                ERROR BRED AND e.what() AND CLR ENDL;
                return 1;
        }
        return 0;
}
