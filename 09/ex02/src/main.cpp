#include "../inc/PmergeMe.h"
#include <cctype>
#include <algorithm>
#include <functional>

std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

std::string normalise(std::string str) {
        auto ret = std::string("");
        auto norm = false;
        for(auto it = str.begin(); it != str.end(); it++) {
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
        auto sorter = PmergeMe();

        auto sequence = std::string("");
        for (auto i = 1; i < argc; ++i) {
                sequence += argv[i];
                sequence += " ";
        }
        auto hasNumber = false;
        for (auto it = sequence.begin(); it != sequence.end(); ++it) {
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
