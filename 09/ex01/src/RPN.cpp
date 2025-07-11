#include "../inc/RPN.h"

RPN::RPN() {}

RPN::RPN(const RPN &src) {
        *this = src;
}

RPN &RPN::operator=(const RPN &rhs) {
        _operations = rhs._operations;
        return *this;
}

RPN::~RPN() {}

template<typename T>
T plop(std::stack<T> &stk, char c = ' ') {
        if(stk.size() < 1) throw std::out_of_range(std::string("unable to pop from stack: (not enough values)\nfor operation : ") + c);
        T tmp = stk.top();
        stk.pop();
        return tmp;
}

#ifndef BONUS
#define foreach(var, val) { __auto_type __it__ = (val).begin(); \
        for(__auto_type var = *__it__; __it__ != (val).end(); __it__++) { var = *__it__; 
#define endforeach }}

void RPN::calculate(std::string data) {
        std::stack<double> stack;
        foreach(c, data)
                switch(c) {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9':
                                stack.push(c - '0');
                                break;
                        case '+':
                                stack.push(plop(stack, c) + plop(stack, c));
                                break;
                        case '-':
                                stack.push(plop(stack, c) - plop(stack, c));
                                break;
                        case '*':
                                stack.push(plop(stack, c) * plop(stack, c));
                                break;
                        case '/':
                                stack.push(plop(stack, c) / plop(stack, c));
                                break;
                        default:
                                if(std::isspace(c)) break;
                                throw std::logic_error(std::string("unknown character '") + c + std::string("'"));
                }
        endforeach
        if(stack.size() == 1) PRINT BGRN AND "stack: " AND plop(stack) AND CLR ENDL;
        else {
                PRINT BGRN AND "stack: [ ";
                while(stack.size() != 0) {
                        PRINT plop(stack);
                        if(stack.size() != 0) PRINT ", ";
                }
                PRINT " ]" CLR ENDL;
        }
}
#else
#define foreach(var, val) { __auto_type __it__ = (val).size(); __it__ -= (val).size(); \
        for(__auto_type var = (val)[__it__]; __it__ != (val).size(); __it__++) { var = (val)[__it__]; 
#define endforeach }}

#define goat(x) __it__ = x
#define getpos() (__it__ - 1)

void RPN::calculate(std::string data) {
        std::stack<double> stack;
        std::stack<int> pos;
        foreach(c, data)
                switch(c) {
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9':
                                stack.push(c - '0');
                                break;
                        case '+':
                                stack.push(plop(stack, c) + plop(stack, c));
                                break;
                        case '-':
                                stack.push(plop(stack, c) - plop(stack, c));
                                break;
                        case '*':
                                stack.push(plop(stack, c) * plop(stack, c));
                                break;
                        case '/':
                                stack.push(plop(stack, c) / plop(stack, c));
                                break;
                        case 'l':
                                pos.push(getpos());
                                break;
                        case 'e':
                                if(plop(stack, c) == 0) break;
                                goat(plop(pos, c));
                                break;
                        case '<': {
                                double a = plop(stack, c);
                                double b = plop(stack, c);
                                stack.push(a);
                                stack.push(b);
                                break;
                        }
                        case 'p': {
                                double tmp = plop(stack, c);
                                PRINT BBLU AND "stack top is: " AND tmp AND CLR ENDL;
                                break;
                        }
                        case 'd': {
                                double a  = plop(stack, c);
                                stack.push(a);
                                stack.push(a);
                                break;
                        }
                        case 'o': {
                                double a  = plop(stack, c);
                                double b  = plop(stack, c);
                                stack.push(b);
                                stack.push(a);
                                stack.push(b);
                                break;
                        }
                        case '_': {
                                double a  = plop(stack, c);
                                (void)a;
                                break;
                        }
                        default:
                                  if(std::isspace(c)) break;
                                  throw std::logic_error(std::string("unknown character '") + c + std::string("'"));
                }
        endforeach
        if(stack.size() == 0) PRINT BGRN "stack: EMPTY" CLR ENDL;
        else if(stack.size() == 1) PRINT BGRN AND "stack: " AND plop(stack) AND CLR ENDL;
        else {
                PRINT BGRN AND "stack: [ ";
                while(stack.size() != 0) {
                        PRINT plop(stack);
                        if(stack.size() != 0) PRINT ", ";
                }
                PRINT " ]" CLR ENDL;
        }
}

// print value from 0 to 10
// 5 5 + 0 l d p 1 + o o - e _ p

#endif
