#include "Form.hpp"

// Canonical Orthodox Form
Form::Form() : _name("none"), _signed(false), _gradeSign(75), _gradeExec(75) {
}

Form::Form(const std::string &name, const int &gradeSign, const int &gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
        if(_gradeSign > MAX_GRADE) throw GradeTooLowException();
        if(_gradeSign < MIN_GRADE) throw GradeTooHighException();
        if(_gradeExec > MAX_GRADE) throw GradeTooLowException();
        if(_gradeExec < MIN_GRADE) throw GradeTooHighException();
}

Form::Form(const Form &src) : _name(src._name), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {
        *this = src;
}

Form &Form::operator=(const Form &rhs) {
	this->_signed = rhs._signed;
	return *this;
}

Form::~Form() {
}

// Accessors
std::string Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_signed;
}

int Form::getGradesign() const {
	return this->_gradeSign;
}

int Form::getGradeexec() const {
	return this->_gradeExec;
}

Form::GradeTooHighException::GradeTooHighException() {}

const char *Form::GradeTooHighException::what() const throw() {
        return "Grade Too High";
}

Form::GradeTooLowException::GradeTooLowException() {}

const char *Form::GradeTooLowException::what() const throw() {
        return "Grade Too Low";
}

Form::NotSignedException::NotSignedException() {}

const char *Form::NotSignedException::what() const throw() {
        return "Form Not Signed";
}

// Methods

void Form::beSigned(Bureaucrat b) {
        if(this->_gradeSign >= b.getGrade()) this->_signed = true;
        else throw GradeTooLowException();
}
