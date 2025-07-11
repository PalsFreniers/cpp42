#include "../inc/PmergeMe.h"

int main(int argc, char *argv[]) {
        PmergeMe sorter;

        std::string sequence;
        for (int i = 1; i < argc; ++i) {
                sequence += argv[i];
                sequence += " ";
        }
        bool hasNumber = false;
        for (std::string::iterator it = sequence.begin(); it != sequence.end(); ++it) {
                if (!isdigit(*it)) continue ;
                hasNumber = true;
                break;
        }
        if (!hasNumber) return 1;
        try {
                sorter.run(sequence);
        } catch (std::exception &e) {
                ERROR BRED AND e.what() AND CLR ENDL;
        }
}
