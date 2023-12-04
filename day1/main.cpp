#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>

int combineCharNums(char c1, char c2) {
    std::string num;
    num = num + c1 + c2;
    return stoi(num);
}

std::string getString(char x) {
    std::string s(1, x);
    return s;
}

char getNumChar(const std::string& s, int index) {
    std::unordered_map<std::string, char> number_words;
    number_words["one"] = '1';
    number_words["two"] = '2';
    number_words["three"] = '3';
    number_words["four"] = '4';
    number_words["five"] = '5';
    number_words["six"] = '6';
    number_words["seven"] = '7';
    number_words["eight"] = '8';
    number_words["nine"] = '9';


    for (auto ele : number_words) {
        bool found = true;
        //std::cout << "ele: " << ele.first << std::endl;
        for (int i = 0; i < ele.first.length(); i++) {
            if (index + ele.first.length() <= s.length()) {
                //std::cout << "ele[i]: " << ele.first[i] << " | s[index+i]: " << s[index + i] << "\n";
                if (ele.first[i] != s[index+i]) {
                    found = false;
                    //std::cout << "not it.\n";
                }
            }
            else {
                found = false;
            }
        }
        if (found) {
            return ele.second;
        }
    }

    return 'x';
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

    for (int i = 0; i < input_vec.size(); i++) {
        char first;
        char second;
        bool first_flag = false;
        for (int j = 0; j < input_vec[i].length(); j++) {
            char currChar = input_vec[i][j];
            if (std::regex_match(getString(currChar), pattern)) {
                if (!first_flag) {
                    first = currChar;
                    first_flag = true;
                }
                second = currChar;
            }
            if (getNumChar(input_vec[i], j) != 'x') {
                currChar = getNumChar(input_vec[i], j);
                if (!first_flag) {
                    first = currChar;
                    first_flag = true;
                }
                second = currChar;
            }
            
        }
        sum += combineCharNums(first, second);
    }

    std::cout << "SUM: " << sum << "\n";
    
    /*std::string test = "fewbbovwov6ixsixn";

    for (int i = 0; i < test.length(); i++) {
        char check = getNumChar(test, i);
        if (check != 'x') {
            std::cout << "at index: " << i << " num: " << check << "\n";
        }
    }*/

    return sum;
}