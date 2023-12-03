#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <unordered_map>

bool checkWordNum(const std::string& s) {
	std::vector<std::string> numWords = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	bool valid;
	for (std::string ele : numWords) {
		valid = true;
		for (int i=0; i<ele.length(); i++) {
			if (ele[i]!=s[i]) {
				valid=false;
			}
		}
		if (valid) {
			return true;
		}
	}
	return false;
}

std::string getWordNum(const std::string& s) {
	std::vector<std::string> numWords = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	std::unordered_map<std::string, std::string> numWordMap;
	numWordMap["one"] = "1";
	numWordMap["two"] = "2";
	numWordMap["three"] = "3";
	numWordMap["four"] = "4";
	numWordMap["five"] = "5";
	numWordMap["six"] = "6";
	numWordMap["seven"] = "7";
	numWordMap["eight"] = "8";
	numWordMap["nine"] = "9";

	for (std::string ele : numWords) {
		if (s.find(ele) != std::string::npos) {
			return numWordMap[ele];
		}
	}

	return "-1";

}

int main() {

	std::ifstream file("input.txt");
	std::string lineString;
	std::vector<std::string> input;

	while (getline(file, lineString)) {
		input.push_back(lineString);
	}

	file.close();

	//input = {"1abc2", "pqr3stu8vwx", "afourb2c3d4e5f", "treb7uchet"};

	int sum = 0;
	//std::cout << "running total: " << sum << std::endl;
	std::regex pattern("\\d");
	for (auto it = input.begin(); it!=input.end(); it++) {
		//std::cout << *it << std::endl;
		std::string s = *it;
		std::string first, second;
		bool firstFlag(false);
		for (int i=0; i<s.length(); i++) {
			std::string checkChar(1, s[i]);
			std::string checkWord = s.substr(i, 5);
			if (std::regex_match(checkChar, pattern)) {
				if (!firstFlag) {
					first = checkChar;
					firstFlag = true;
				}
				second = checkChar;
			}
			else {
				if (checkWordNum(checkWord)) {
					if (!firstFlag) {
						first = getWordNum(checkWord);
						firstFlag=true;
					}
					second = getWordNum(checkWord);
				}
			}
		}
		//std::cout << first << second << "\n";
		sum+=std::stoi(first.append(second));
		//std::cout << "running total: " << sum << std::endl;
	}

	std::cout << "SUM: " << sum << std::endl;

	return 0;

}
