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

    int sum = 0;
    std::regex pattern("\\d");

    //int RED = 12;
    //int GREEN = 13;
    //int BLUE = 14;
    for (int i = 0; i < input_vec.size(); i++) {
        //bool validGame = true;
        int minRed=0;
        int minGreen=0;
        int minBlue=0;
        std::vector<std::string> tokens = splitOn(input_vec[i], ' ');
        /*for (auto s : tokens) {
            std::cout << s << "\n";
        }
        return -1;*/
        for (int j = 0; j < tokens.size(); j++) {
            // first char in string 
            if (std::regex_match(getString(tokens[j][0]), pattern)) {
                switch (tokens[j+1][0]) {
                case 'r':
                    if (stoi(tokens[j]) > minRed) {
                        minRed = stoi(tokens[j]);
                    }
                    break;
                case 'g':
                    if (stoi(tokens[j]) > minGreen) {
                        minGreen = stoi(tokens[j]);
                    }
                    break;
                case 'b':
                    if (stoi(tokens[j]) > minBlue) {
                        minBlue = stoi(tokens[j]);
                    }
                    break;
                default:
                    break;
                }
            }
        }

        //if (validGame) {
            //sum += i + 1;
        //}
        sum += minRed * minGreen * minBlue;
    }

    std::cout << "SUM: " << sum << std::endl;
    return 0;
}