#include "Command.hpp"

namespace Pals {
        Command::Command() : m_line("") {}

        Command::Command(std::string line) : m_line(line) {}

        Command::Command(const Command &other) {
                *this = other;
        }

        Command::~Command() {}

        Command &Command::operator=(const Command &other) {
                m_line = other.m_line;
                return *this;
        }

        char low(char c) {
                if(c >= 'A' && c <= 'Z')
                        return c + ' ';
                return c;
        }

        std::string to_lower(std::string s) {
                std::string ret = "";
                for(size_t i = 0; i < s.length(); i++) ret.insert(ret.end(), low(s[i])); 
                return ret;
        }

        CommandType Command::command() {
                return m_line == "ADD" ? ADD :
                       m_line == "SEARCH" ? PRINT :
                       m_line == "EXIT" ? EXIT : NONE;
        }
}
