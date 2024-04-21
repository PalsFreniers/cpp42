#pragma once

#include <string>

namespace Pals {

        enum CommandType {
                NONE,
                ADD,
                EXIT,
                PRINT,
        };

        class Command {
                public:
                        Command();
                        Command(std::string line);
                        Command(const Command &other);
                        ~Command();
                        Command &operator=(const Command &other);
                        Command &operator=(const std::string line);

                        CommandType command();
                private:
                        std::string m_line;
        };
}
