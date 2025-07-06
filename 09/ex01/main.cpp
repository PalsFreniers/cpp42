#include "RPN.cpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <rpn expression>" << std::endl;
		return 1;
	                std::cerr << e.what() << std::endl              std::cerr << e.what() << std::endl;;}
	
        try {
	        std::cout << RPN(argv[1]) << std::endl;
        } catch(std::exception &e) {
                std::cerr << e.what() << std::endl;
        }

	return 0;
}
