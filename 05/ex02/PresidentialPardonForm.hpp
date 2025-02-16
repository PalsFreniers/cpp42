#pragma once

#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	// Orthodox Canonical PresidentialPardonForm
	PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm&operator=(const PresidentialPardonForm &rhs);
	virtual ~PresidentialPardonForm();

        virtual void execute(Bureaucrat const &executor) const;

private:
        std::string _target;
};
