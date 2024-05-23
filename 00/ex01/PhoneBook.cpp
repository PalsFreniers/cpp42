#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : contacts(new Contact[8]), i(0), nbr(0) {}

PhoneBook::PhoneBook(const PhoneBook &other) {
        *this = other;
}

PhoneBook::~PhoneBook() {
        delete[] contacts;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other) {
        if (this != &other) {
                delete[] contacts;
                contacts = new Contact[8];
                for (int i = 0; i < 8; i++) {
                        contacts[i] = other.contacts[i];
                }
                i = other.i;
        }
        return *this;
}

void PhoneBook::addContact() {
        if (i == 8)
                i = 0;
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
        contacts[i] = Contact(fname, lname, nickname, phone, secret);
        ++i;
        if(nbr < 8) nbr++;
        goto end;
err:
        std::cout << "Error Contact can't have empty fields" << std::endl;
end:
        return;
}

void PhoneBook::print() const {
        std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
        for (int j = 0; j < nbr; j++) {
                std::cout << "|" << std::setw(10) << j << "|";
                contacts[j].print();
                std::cout << std::endl;
        }
}

void PhoneBook::show(int i) const {
        if(std::cin.fail()) {
                std::cout << "This is not even a number" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
        }
        if(i < 0 || i > 8) {
                std::cout << "you dont have that much friends" << std::endl;
                return;
        }
        contacts[i].show();
}

bool PhoneBook::hasContact() const {
        return nbr > 0;
}
