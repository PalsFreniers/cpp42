#pragma once

#include <string>

class Harl {
public:
        Harl();
        Harl(const Harl &other);
        ~Harl();
        Harl &operator=(const Harl &other);
        void complain(std::string level);
private:
        void debug();
        void info();
        void warning();
        void error();
};
