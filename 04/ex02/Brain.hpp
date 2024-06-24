#pragma once

#include <string>

class Brain {
public:
        Brain();
        ~Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);

        void setIdea(std::string idea, int id);
        std::string getIdea(int id);

        class BadIndexException : public std::exception {
        public:
                virtual const char *what() const throw();
        };
private:
        std::string ideas[100];
};
