#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

std::string getString(char x) {
    std::string s(1, x);
    return s;
}

bool checkNearby(const std::vector<std::string>& grid, int x, int y) {
    std::regex pattern("[^0-9]");
    bool noLeft = (x == 0) ? true : false;
    bool noRight = (x == grid[0].length() - 1) ? true : false;
    bool noTop = (y == 0) ? true : false;
    bool noBottom = (y == grid.size() - 1) ? true : false;

    if (!noLeft) {
        if (grid[y][x - 1] == '*') {
            return true;
        }
        //std::cout << "checked left |";
    }
    if (!noRight) {
        if (grid[y][x + 1] == '*') {
            return true;
        }
        //std::cout << "checked R |";
    }
    if (!noTop) {
        if (grid[y - 1][x] == '*') {
            return true;
        }
        //std::cout << "checked T|";
    }
    if (!noBottom) {
        if (grid[y + 1][x] == '*') {
            return true;
        }
        //std::cout << "checked B |";
    }
    if (!noTop && !noLeft) {
        if (grid[y - 1][x - 1] == '*') {
            return true;
        }
        //std::cout << "checked TL |";
    }
    if (!noTop && !noRight) {
        if (grid[y - 1][x + 1] == '*') {
            return true;
        }
        //std::cout << "checked TR |";
    }
    if (!noBottom && !noLeft) {
        if (grid[y + 1][x - 1] == '*') {
            return true;
        }
        //std::cout << "checked BL |";
    }
    if (!noBottom && !noRight) {
        if (grid[y + 1][x + 1] == '*') {
            return true;
        }
        //std::cout << "checked BR |";
    }

    return false;
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
    for (int y = 0; y < input_vec.size(); y++) {
        std::string row = input_vec[y];
        std::string currNum = "";
        bool validNum = false;
        for (int x = 0; x < row.length(); x++) {
            if (std::regex_match(getString(row[x]), pattern)) {
                //std::cout << std::endl << getString(row[x]) << " | x: " << x << " y: " << y << std::endl;
                if (checkNearby(input_vec, x, y)) {
                    validNum = true;
                }

                currNum.append(getString(row[x]));

            }
            else {

                if (validNum) {
                    sum += stoi(currNum);
                    //std::cout << "Valid: " << currNum << " | ";
                }
                else if (!currNum.empty()) {
                    //std::cout << "Invalid: " << currNum << " | ";
                }
                validNum = false;
                currNum.clear();

            }
        }
        if (validNum) {
            sum += stoi(currNum);
            //std::cout << "Valid: " << currNum << " | ";
        }
        validNum = false;
        currNum.clear();
    }


    //323053
    //538121
    std::cout << "SUM: " << sum << std::endl;
    return 0;
}
