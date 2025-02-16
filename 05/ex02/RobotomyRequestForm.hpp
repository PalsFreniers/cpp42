#pragma once

#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	// Orthodox Canonical RobotomyRequestForm
	RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm&operator=(const RobotomyRequestForm &rhs);
	virtual ~RobotomyRequestForm();

        virtual void execute(Bureaucrat const &executor) const;

private:
        std::string _target;
};
