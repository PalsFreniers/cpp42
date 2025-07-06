#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <climits>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Please provide an input file" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return (1);
	}
	const std::string inputFile(argv[1]);
	const std::string csvFile("data.csv");

	int earliestYear = INT_MAX;
        BitcoinExchange btc;
	if (!btc.loadDatabase(csvFile, earliestYear)) return (1);

	btc.processUserInput(inputFile, earliestYear);
        return 0;
}
