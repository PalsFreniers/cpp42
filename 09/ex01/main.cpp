#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>

#define OP_ADD 1
#define OP_SUB 2
#define OP_MUL 3
#define OP_DIV 4

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <rpn expression>" << std::endl;
		return 1;
	}
	
	std::stringstream ss(argv[1]);
	std::string token;
	int op;
	double result = 0;
	std::stack<double> stack;

	while (std::getline(ss, token, ' ')) {
		if (token == "+") {
			op = OP_ADD;
		} else if (token == "-") {
			op = OP_SUB;
		} else if (token == "*") {
			op = OP_MUL;
		} else if (token == "/") {
			op = OP_DIV;
		} else {
			char *end;
			result = std::strtod(token.c_str(), &end);
			if (*end != '\0') {
				std::cerr << "Error: invalid number" << std::endl;
				return 1;
			}
			if (result >= 10) {
				std::cerr << "Error: number too big" << std::endl;
				return 1;
			}
			stack.push(result);
			continue;
		}

		if (stack.size() < 2) {
			std::cerr << "Error: invalid expression (missing operands)" << std::endl;
			return 1;
		}

		double right = stack.top();
		stack.pop();
		double left = stack.top();
		stack.pop();

		switch (op) {
			case OP_ADD:
				result = left + right;
				break;
			case OP_SUB:
				result = left - right;
				break;
			case OP_MUL:
				result = left * right;
				break;
			case OP_DIV:
				if (right == 0) {
					std::cerr << "Error: division by zero" << std::endl;
					return 1;
				}
				result = left / right;
				break;
		}
		stack.push(result);
	}

	if (stack.size() != 1) {
		std::cerr << "Error: invalid expression (too many results)" << std::endl;
		return 1;
	}

	result = stack.top();
	stack.pop();

	std::cout << result << std::endl;
	return 0;
}
