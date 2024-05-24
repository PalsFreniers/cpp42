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
        void show(int i, bool valid) const;
        bool hasContact() const;
private:
        Contact contacts[8];
        int _i;
};

