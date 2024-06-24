#include "Brain.hpp"

Brain::Brain() {

}

Brain::~Brain() {

}

Brain::Brain(const Brain &other) {
        *this = other;
}

Brain &Brain::operator=(const Brain &other) {
        for(int i = 0; i < 100; i++) ideas[i] = other.ideas[i];
        return *this;
}

void Brain::setIdea(std::string idea, int id) {
        if(id < 0 || id >= 100) throw Brain::BadIndexException();
        ideas[id] = idea;
}

std::string Brain::getIdea(int id) {
        if(id < 0 || id >= 100) throw Brain::BadIndexException();
        return ideas[id];
}

const char *Brain::BadIndexException::what() const throw() {
        return "unable to get idea";
}
