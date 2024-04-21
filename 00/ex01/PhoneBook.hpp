#pragma once

#include "Contact.hpp"

class PhoneBook {
public:
        PhoneBook();
        PhoneBook(const PhoneBook &other);
        ~PhoneBook();
        PhoneBook &operator=(const PhoneBook &other);

        void addContact();
        void print() const;
        void show(int i) const;
        bool hasContact() const;
private:
        Contact *contacts;
        int i;
        int nbr;
};

