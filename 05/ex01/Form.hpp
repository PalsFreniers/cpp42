#pragma once

#include <string>

class Form {
public:
        Form();
        Form(std::string name, int grade, int required);
        Form(const Form &other);
        Form &operator=(const Form &other);

        class GradeTooHighException : public std::exception {
        public:
                GradeTooHighException();
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
                GradeTooLowException();
                const char *what() const throw();
        };
private:
        const std::string _name;
        bool _signed;
        const int _grade;
        const int _required;
};
