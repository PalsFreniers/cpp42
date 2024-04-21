#pragma once

#include <string>

class Contact {
public:
        Contact();
        Contact(std::string fname, std::string lname, std::string nickname, std::string phone, std::string secret);
        Contact(const Contact &other);
        ~Contact();
        Contact &operator=(const Contact &other);

        void print() const;
        void show() const;
private:
        std::string fname;
        std::string lname;
        std::string nickname;
        std::string phone;
        std::string secret;
};
