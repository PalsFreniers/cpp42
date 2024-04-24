#include "Harl.hpp"
#include <iostream>

#define UNUSED(x) (void)(x)

Harl::Harl() {}

Harl::Harl(const Harl &other) {
       UNUSED(other); 
}

Harl::~Harl() {}

Harl &Harl::operator=(const Harl &other) {
        UNUSED(other);
        return *this;
}

void Harl::complain(std::string level) {
        void (Harl::*funcs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
        std::string lvls[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
        for(int i = 0; i < 4; i++) if(level == lvls[i]) (this->*funcs[i])();
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
