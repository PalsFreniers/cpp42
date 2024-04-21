#include <iostream>
#include "Command.hpp"
#include "PhoneBook.hpp"

void add(PhoneBook &book) {
        book.addContact();
}

void search(PhoneBook &book) {
        if(!book.hasContact()) {
                std::cout << "please add contacts before trying to search in them" << std::endl;
                return;
        }
        book.print();
        std::cout << "PalPhone Search> ";
        int i;
        std::cin >> i;
        book.show(i);
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
                                std::cout << "Unable to find Command : '" << line << '\'' << std::endl;
                                break;
                }
                std::cout << "PalPhone> ";
        } while(std::getline(std::cin, line)); 
ext:
        std::cout << "I hope you had fun Good Bye!" << std::endl;
        return 0;
}
