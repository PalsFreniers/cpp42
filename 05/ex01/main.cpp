#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main() {
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
                Form f("testForm", 50, 50);
                Bureaucrat a = Bureaucrat("david", 1);
                a.signForm(f);
                std::cout << f;
        }
        {
                Form f("testForm", 50, 50);
                Bureaucrat a = Bureaucrat("david", 130);
                a.signForm(f);
                std::cout << f;
        }
}
