#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("joris"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
        if(grade > MAX_GRADE) throw GradeTooLowException();
        if(grade <= MIN_GRADE) throw GradeTooLowException();
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name) {
        *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
        _grade = other.getGrade();
        return *this;
}

const std::string &Bureaucrat::getName() const {
        return _name;
}

int Bureaucrat::getGrade() const {
        return _grade;
}

Bureaucrat &Bureaucrat::operator++() {
        if(_grade - 1 < MAX_GRADE) throw GradeTooHighException();
        _grade--;
        return *this;
}

Bureaucrat &Bureaucrat::operator--() {
        if(_grade + 1 > MAX_GRADE) throw GradeTooLowException();
        _grade++;
        return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
        return "Grade Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
        return "Grade Too Low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
        out << b.getName() << std::string(", bureaucrat grade ") << b.getGrade();
        return out;
}
