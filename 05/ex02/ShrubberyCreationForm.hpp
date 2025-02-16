#pragma once

#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	// Orthodox Canonical ShrubberyCreationForm
	ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm&operator=(const ShrubberyCreationForm &rhs);
	virtual ~ShrubberyCreationForm();

        virtual void execute(Bureaucrat const &executor) const;

private:
        std::string _target;
};
