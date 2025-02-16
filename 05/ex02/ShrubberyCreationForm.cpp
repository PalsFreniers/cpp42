#include "ShrubberyCreationForm.hpp"
#include <AForm.hpp>
#include <fstream>
#include <stdexcept>

// Canonical Orthodox ShrubberyCreationForm
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("none"){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("ShrubberyCreationForm", 145, 137) {
        *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
        AForm::operator=(rhs);
        this->_target = rhs._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
        if(!getSigned()) throw NotSignedException();
        if(executor.getGrade() > getGradeexec()) throw GradeTooLowException();
        std::ofstream out;
        out.open((_target + "_shrubbery").c_str());
        if(!out.is_open()) throw std::runtime_error("unable to open file " + _target + "_shrubbery");
        for (int i = 0; i < 12; i++) out << "tree ";
        out.close();
}
