#include "../inc/PmergeMe.h"
#include <cctype>
#include <algorithm>
#include <functional>

inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

std::string normalise(std::string str) {
        std::string ret;
        bool norm = false;
        for(__auto_type it = str.begin(); it != str.end(); it++) {
                if(!std::isspace(*it)) {
                        norm = false;
                        ret += (*it);
                        continue;
                }
                if(norm) continue;
                ret += ' ';
                norm = true;
        }
        
        return ret;
}

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
                sequence = normalise(sequence);
                sorter.run(sequence);
        } catch (std::exception &e) {
                ERROR BRED AND e.what() AND CLR ENDL;
        }
}
