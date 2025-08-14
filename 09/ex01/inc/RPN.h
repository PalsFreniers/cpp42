#pragma once

# include <iostream>
# include <string>
# include <stdexcept>
# include <stack>
# include <cerrno>
# include <climits>
# include <cstdlib>
# include "printUtils.h"
# include "colors.h"

#define auto __auto_type

class RPN
{
        public:
                RPN();
                RPN(const RPN &src);
                RPN&operator=(const RPN &rhs);
                ~RPN();
                void calculate(std::string data);
        private:
                std::stack<int> _operations;
};
