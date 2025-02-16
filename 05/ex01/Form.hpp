#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Form
{
public:
	// Orthodox Canonical Form
	Form();
        Form(const std::string &name, const int &gradeSign, const int &gradeExec);
	Form(const Form &src);
	Form&operator=(const Form &rhs);
	~Form();

	// Accessors
	std::string getName() const;
	bool getSigned() const;
	int getGradesign() const;
	int getGradeexec() const;

        void beSigned(Bureaucrat b);

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
	const int _gradeSign;
	const int _gradeExec;
};

std::ostream &operator<<(std::ostream &out, const Form &b);
