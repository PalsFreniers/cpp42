#include <iostream>
#include <sstream>
#include <string>
#include <csignal>
#include "Command.hpp"
#include "Exception.hpp"
#include "PhoneBook.hpp"
#define foreach(name, data) for(__typeof__((data).begin()) name = (data).begin(); name != (data).end(); name++)
#define UNUSED(x) (void)(x)

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
        if(std::cin.eof()) throw Pals::Utils::Exception();
        foreach(it, tmp) if(std::iscntrl(*it)) valid = false;
        else {
                std::istringstream is(tmp);
                is >> i;
                if(is.fail()) valid = false;
        }
        try {
                book.show(i, valid);
        } catch (Pals::Utils::Exception *) { 
                goto retry;
        }
}

void sh(int n) {
        UNUSED(n);
        std::cout << "all this is because of kiroussa" << std::endl;
        std::cout << std::endl << "PalPhone> ";
        std::cout.flush();
}

int main() {
        std::signal(SIGINT, sh);
        std::signal(SIGQUIT, sh);
        PhoneBook book;
        std::cout << "Welcome to PalPhone the PalWorld phonebook" << std::endl;
        std::string line = "";
        Pals::Command cmd;
        do {
                std::cout.flush();
                if(line.empty()) {
                        goto ctn;
                }
                cmd = line;
                foreach(it, line) if(std::iscntrl(*it)) goto err;
                switch (cmd.command()) {
                        case Pals::ADD:
                                add(book);
                                break;
                        case Pals::PRINT:
                                try {
                                        search(book);
                                } catch(Pals::Utils::Exception *) {
                                        goto ext;
                                }
                                break;
                        case Pals::EXIT:
                                goto ext;
                                break;
                        default:
                                std::cout << "\033[1;31m[ERROR]\033[0m => Unable to find Command : '" << line << "'" << std::endl;
                                break;
                }
ctn:
                std::cout << "PalPhone> ";
                continue;
err:
                std::cout << "\033[1;31m[ERROR]\033[0m => found control sequences in command" << std::endl;
                goto ctn;
        } while(std::getline(std::cin, line)); 
ext:
        std::cout << "I hope you had fun Good bye and good luck catching new pals!" << std::endl;
        return 0;
}
