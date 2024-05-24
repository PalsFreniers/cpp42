#pragma once

#include <exception>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define extends :

namespace Pals {
        namespace Utils {
                class Exception extends public std::exception {
                public:
                        Exception();
                        ~Exception() throw();
                        const char *what() const throw();
                };
        }
}
