#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

std::string slurp(std::ifstream &influx) {
        std::ostringstream tmp;
        tmp << influx.rdbuf();
        return tmp.str();
}

void patch(std::string &str, std::string s1, std::string s2) {
        std::size_t index = str.find(s1);
        while(index != std::string::npos) {
                str.erase(index, s1.length());
                str.insert(index, s2);
                index = str.find(s1);
        }
}

int main(int c, const char *args[]) {
        if(c < 4 || c > 4) {
                std::cerr << "Usage: " << args[0] << " <filename> <str_to_replace> <str>" << std::endl;
                return 1;
        }
        std::string filename(args[1]);
        std::string outfilename(filename + ".replace");
        std::string s1(args[2]);
        std::string s2(args[3]);
        std::string content;
        std::ifstream influx(filename.c_str());
        if(!influx.is_open()) {
                std::cerr << "unable to open file " << filename << std::endl;
                return 1;
        }
        content = slurp(influx);
        influx.close();
        patch(content, s1, s2);
        std::ofstream outflux(outfilename.c_str()); 
        if(!outflux.is_open()) {
                std::cerr << "unable to open file " << filename << std::endl;
                return 1;
        }
        outflux << content;
        outflux.close();
}
