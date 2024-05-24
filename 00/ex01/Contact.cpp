#include "Contact.hpp"
#include <iomanip>
#include <iostream>

Contact::Contact() : fname(""), lname(""), nickname(""), phone(""), secret("") {}

Contact::Contact(const Contact &other) {
        *this = other;
}

Contact::Contact(std::string fname, std::string lname, std::string nickname, std::string phone, std::string secret) : fname(fname), lname(lname), nickname(nickname), phone(phone), secret(secret) {}

Contact::~Contact() {}

Contact &Contact::operator=(const Contact &other) {
        if (this != &other) {
                fname = other.fname;
                lname = other.lname;
                nickname = other.nickname;
                phone = other.phone;
                secret = other.secret;
        }
        return *this;
}

std::string truncField(std::string field) {
        if (field.length() > 10) field = field.substr(0, 9) + ".";
        return field;
}

void Contact::print() const {
        std::cout << std::setw(10) << truncField(fname) << "|";
        std::cout << std::setw(10) << truncField(lname) << "|";
        std::cout << std::setw(10) << truncField(nickname) << "|";
}

void Contact::show() const {
        std::cout << "First Name: " << fname << std::endl;
        std::cout << "Last Name: " << lname << std::endl;
        std::cout << "Nickname: " << nickname << std::endl;
        std::cout << "Phone Number: " << phone << std::endl;
        std::cout << "Darkest Secret: " << secret << std::endl;
}
