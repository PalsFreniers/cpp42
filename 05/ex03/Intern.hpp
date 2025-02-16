#pragma once

#include "Form.hpp"
#include <string>

class Intern {
public:
        Intern();
        Intern(const Intern &other);
        ~Intern();
        Intern &operator=(const Intern &other);

        Form *makeForm(std::string form, std::string target);
};
