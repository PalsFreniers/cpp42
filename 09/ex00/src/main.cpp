#include <iostream>
#include "../inc/colors.h"
#include "../inc/printUtils.h"
#include "../inc/StockMarket.h"
#include "../inc/BitcoinExchange.h"

int main(int argc, char *argv[]) {
        if(argc != 2) ERROR BRED AND "unable to open file: (no input file sspecified)" AND CLR ENDL;
        try {
                StockMarket market = StockMarket();
                BitcoinExchange history;
                history.loadFile(argv[1]);
                history.printValue(market);
        } catch(std::exception &e) {
                ERROR BRED AND e.what() AND CLR ENDL;
                return 1;
        }
        return 0;
}
