#include "RobotomyRequestForm.hpp"
#include <Form.hpp>
#include <cstdlib>

// Canonical Orthodox RobotomyRequestForm
RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("none"){
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form("RobotomyRequestForm", 72, 45) {
        *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
        Form::operator=(rhs);
        this->_target = rhs._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
        if(!getSigned()) throw NotSignedException();
        if(executor.getGrade() > getGradeexec()) throw GradeTooLowException();
        std::system("ffplay -v 0 -nodisp -autoexit .gitmuse/drill.mp3 >/dev/null 2>/dev/null");
        if(std::rand() % 2 == 1) std::cout << "Robotomisation of " << _target << " has been successfull" << std::endl;
        else std::cout << "Robotomisation of " << _target << " has not been successfull" << std::endl;

}
