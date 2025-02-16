#include "AForm.hpp"

// Canonical Orthodox AForm
AForm::AForm() : _name("none"), _signed(false), _gradeSign(75), _gradeExec(75) {
}

AForm::AForm(const std::string &name, const int &gradeSign, const int &gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
        if(_gradeSign > MAX_GRADE) throw GradeTooLowException();
        if(_gradeSign < MIN_GRADE) throw GradeTooHighException();
        if(_gradeExec > MAX_GRADE) throw GradeTooLowException();
        if(_gradeExec < MIN_GRADE) throw GradeTooHighException();
}

AForm::AForm(const AForm &src) : _name(src._name), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {
        *this = src;
}

AForm &AForm::operator=(const AForm &rhs) {
	this->_signed = rhs._signed;
	return *this;
}

AForm::~AForm() {
}

// Accessors
std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSigned() const {
	return this->_signed;
}

int AForm::getGradesign() const {
	return this->_gradeSign;
}

int AForm::getGradeexec() const {
	return this->_gradeExec;
}

AForm::GradeTooHighException::GradeTooHighException() {}

const char *AForm::GradeTooHighException::what() const throw() {
        return "Grade Too High";
}

AForm::GradeTooLowException::GradeTooLowException() {}

const char *AForm::GradeTooLowException::what() const throw() {
        return "Grade Too Low";
}

AForm::NotSignedException::NotSignedException() {}

const char *AForm::NotSignedException::what() const throw() {
        return "Form Not Signed";
}

// Methods

void AForm::beSigned(Bureaucrat b) {
        if(this->_gradeSign >= b.getGrade()) this->_signed = true;
        else throw GradeTooLowException();
}
