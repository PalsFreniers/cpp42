#include "Intern.hpp"
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern::~Intern() {}
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

Form *Intern::makeForm(std::string form, std::string target) {
        if(form == "robotomy request") return new RobotomyRequestForm(target);
        if(form == "shrubbery creation") return new ShrubberyCreationForm(target);
        if(form == "presidential pardon") return new PresidentialPardonForm(target);
        std::cout << "unable to create a form for " << form << std::endl;
        return NULL;
}
