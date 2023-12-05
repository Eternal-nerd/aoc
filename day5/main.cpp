#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

std::string getString(char x) {
    std::string s(1, x);
    return s;
}

std::vector<std::string> splitOn(const std::string& s, char delim) {
    std::vector<std::string> returnVal;
    std::string temp;
    for (char c : s) {
        if (c == delim) {
            if (temp.size() >0) {
                returnVal.push_back(temp);
                temp.clear();
            }
        }
        else {
            temp.append(getString(c));
        }
    }
    if (!temp.empty()) {
        returnVal.push_back(temp);
    }
    return returnVal;
}

int main() {

    std::ifstream file("input.txt");
    std::string line;
    std::vector<std::string> input_vec;
    while (std::getline(file, line)) {
        input_vec.push_back(line);
    }
    file.close();


    //std::cout << "SUM: " << sum << std::endl;
    return 0;
}
