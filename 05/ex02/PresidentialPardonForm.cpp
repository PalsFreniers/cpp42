#include "PresidentialPardonForm.hpp"
#include <AForm.hpp>
#include <fstream>
#include <iostream>
#include <stdexcept>

// Canonical Orthodox PresidentialPardonForm
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("none"){
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm("PresidentialPardonForm", 25, 5) {
        *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
        AForm::operator=(rhs);
        this->_target = rhs._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
        if(!getSigned()) throw NotSignedException();
        if(executor.getGrade() > getGradeexec()) throw GradeTooLowException();
        std::cout << _target << " has been pardoned by Zaphod Beeblbrox" << std::endl;
}
