#include "Bureaucrat.hpp"
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <cstdlib>
#include <ctime>
#include <exception>

int main() {
        std::srand(std::time(NULL));
        try {
                Bureaucrat a = Bureaucrat("david", 150);
                for(int i = 0; i < 151; i++) {
                        std::cout << a << std::endl;
                        ++a;
                }
        } catch(std::exception &e) {
                std::cout << e.what() << std::endl;
        }
        try {
                Bureaucrat a = Bureaucrat("david", 1);
                for(int i = 0; i < 151; i++) {
                        std::cout << a << std::endl;
                        --a;
                }
        } catch(std::exception &e) {
                std::cout << e.what() << std::endl;
        }
        try {
                Bureaucrat a = Bureaucrat("david", 0);
        } catch(std::exception &e) {
                std::cout << e.what() << std::endl;
        }
        try {
                Bureaucrat a = Bureaucrat("david", 180);
        } catch(std::exception &e) {
                std::cout << e.what() << std::endl;
        }
        {
                Bureaucrat a = Bureaucrat("david", 1);
                ShrubberyCreationForm f("Home");
                a.signForm(f);
                a.executeForm(f);
        }
        {
                Bureaucrat a = Bureaucrat("david", 1);
                PresidentialPardonForm f("Home");
                a.signForm(f);
                a.executeForm(f);
        }
        {
                Bureaucrat a = Bureaucrat("david", 130);
                Bureaucrat b = Bureaucrat("david2", 1);
                RobotomyRequestForm f("dave");
                a.signForm(f);
                a.executeForm(f);
                b.executeForm(f);
                b.signForm(f);
                a.executeForm(f);
                b.executeForm(f);
        }
}
