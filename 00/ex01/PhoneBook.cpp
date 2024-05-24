#include "PhoneBook.hpp"
#include <exception>
#include <iostream>
#include <iomanip>
#include <limits>
#include "Exception.hpp"

PhoneBook::PhoneBook() : _i(0) {}

PhoneBook::PhoneBook(const PhoneBook &other) {
        *this = other;
}

PhoneBook::~PhoneBook() {}

PhoneBook &PhoneBook::operator=(const PhoneBook &other) {
        if (this != &other) {
                for (int i = 0; i < other._i % 8; i++) {
                        contacts[_i] = other.contacts[_i];
                }
                _i = other._i;
        }
        return *this;
}

void PhoneBook::addContact() {
        std::string fname, lname, nickname, phone, secret;
        std::cout << "First name: ";
        std::getline(std::cin, fname);
        if(fname.empty()) goto err;
        std::cout << "Last name: ";
        std::getline(std::cin, lname);
        if(lname.empty()) goto err;
        std::cout << "Nickname: ";
        std::getline(std::cin, nickname);
        if(nickname.empty()) goto err;
        std::cout << "Phone number: ";
        std::getline(std::cin, phone);
        if(phone.empty()) goto err;
        std::cout << "Darkest secret: ";
        std::getline(std::cin, secret);
        if(secret.empty()) goto err;
        contacts[_i % 8] = Contact(fname, lname, nickname, phone, secret);
        ++_i;
        goto end;
err:
        std::cout << "\033[1;31m[ERROR]\033[0m => Contact can't have empty fields" << std::endl;
end:
        return;
}

void PhoneBook::print() const {
        std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
        for (int j = 0; j < _i % 8; j++) {
                std::cout << "|" << std::setw(10) << j << "|";
                contacts[j].print();
                std::cout << std::endl;
        }
}

void PhoneBook::show(int i, bool valid) const {
        if(!valid) {
                std::cout << "\033[1;31m[ERROR]\033[0m => This is not even a number" << std::endl;
                throw Pals::Utils::Exception();
        }
        if(i < 0 || i > min(_i, 7)) {
                std::cout << "\033[1;31m[ERROR]\033[0m => you dont have that much friends" << std::endl;
                throw Pals::Utils::Exception();
        }
        contacts[i].show();
}

bool PhoneBook::hasContact() const {
        return _i > 0;
}
