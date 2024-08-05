#pragma once

#include <string>
#include <exception>

#define MAX_GRADE 150
#define MIN_GRADE 1

class Bureaucrat {
public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);

        const std::string &getName() const;
        int getGrade() const;

        Bureaucrat &operator++();
        Bureaucrat &operator--();

        class GradeTooHighException : std::exception {
        public:
                GradeTooHighException();
                const char *what() const throw();
        };

        class GradeTooLowException : std::exception {
        public:
                GradeTooLowException();
                const char *what() const throw();
        };

private:
        const std::string _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
