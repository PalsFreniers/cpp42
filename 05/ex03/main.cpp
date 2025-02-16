#include "Bureaucrat.hpp"
#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <cstdlib>
#include <ctime>

int main() {
        std::srand(std::time(NULL));
        Intern i;
        Form *f1, *f2, *f3;
        f1 = i.makeForm("shrubbery creation", "42School");
        f2 = i.makeForm("presidential pardon", "Xavier Niel");
        f3 = i.makeForm("robotomy request", "Bender");
        i.makeForm("dummy", "test");
        Bureaucrat b = Bureaucrat("dave", 1);
        b.signForm(*f1);
        b.executeForm(*f1);
        b.signForm(*f2);
        b.executeForm(*f2);
        b.signForm(*f3);
        b.executeForm(*f3);

        delete f1;
        delete f2;
        delete f3;
}
