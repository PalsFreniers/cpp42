#include <iostream>
#include <sstream>
#include <string>
#include "Command.hpp"
#include "Exception.hpp"
#include "PhoneBook.hpp"

void add(PhoneBook &book) {
        book.addContact();
}

void search(PhoneBook &book) {
        if(!book.hasContact()) {
                std::cout << "\033[1;31m[ERROR]\033[0m => please add contacts before trying to search in them" << std::endl;
                return;
        }
        book.print();
retry:
        std::cout << "PalPhone Search> ";
        std::cout.flush();
        int i = -1;
        std::string tmp;
        bool valid = true;
        std::getline(std::cin, tmp);
        if(tmp.empty()) valid = false;
        else {
                std::istringstream is(tmp);
                is >> i;
                if(is.fail()) valid = false;
        }
        try {
                book.show(i, valid);
        } catch (Pals::Utils::Exception) { 
                goto retry;
        }
}

int main() {
        PhoneBook book;
        std::cout << "Welcome to PalPhone the PalWorld phonebook" << std::endl;
        std::string line = "";
        std::cout << "PalPhone> ";
        do {
                if(line.empty()) {
                        continue;
                }
                Pals::Command cmd = line;
                switch (cmd.command()) {
                        case Pals::ADD:
                                add(book);
                                break;
                        case Pals::PRINT:
                                search(book);
                                break;
                        case Pals::EXIT:
                                goto ext;
                                break;
                        default:
                                std::cout << "\033[1;31m[ERROR]\033[0m => Unable to find Command : '" << line << "'" << std::endl;
                                break;
                }
                std::cout << "PalPhone> ";
        } while(std::getline(std::cin, line)); 
ext:
        std::cout << "I hope you had fun Good bye and good luck cathcing new pals!" << std::endl;
        return 0;
}
