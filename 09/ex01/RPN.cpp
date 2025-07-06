#include "RPN.hpp"
#include <stack>
#include <stdexcept>

double plop(std::stack<double> &stk) {
        double tmp = stk.top();
        stk.pop();
        return tmp;
}

double RPN(std::string prog) {
	std::string token;
	int op;
	double result = 0;
	std::stack<double> stack;

        for(std::string::iterator it = prog.begin(); it != prog.end(); it++) {
                switch(*it) {
                [[fallthrough]]
                        case '0':
                [[fallthrough]]
                        case '1':
                [[fallthrough]]
                        case '2':
                [[fallthrough]]
                        case '3':
                [[fallthrough]]
                        case '4':
                [[fallthrough]]
                        case '5':
                [[fallthrough]]
                        case '6':
                [[fallthrough]]
                        case '7':
                [[fallthrough]]
                        case '8':
                        case '9':
                                stack.push(*it - '0');
                                break;
                        case '+': {
                                double a = plop(stack);
                                double b = plop(stack);
                                stack.push(b + a)
                                break;
                        }
                        case '-': {
                                double a = plop(stack);
                                double b = plop(stack);
                                stack.push(b - a);
                                break;
                        }
                        case '*': {
                                double a = plop(stack);
                                double b = plop(stack);
                                stack.push(b * a)
                                break;
                        }
                        case '/': {
                                double a = plop(stack);
                                double b = plop(stack);
                                stack.push(b / a)
                                break;
                        }
                        case ' ': continue;
                        default: throw std::logic_error(std::string("bad token ") + *it);
                }
        }
}
