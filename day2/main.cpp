#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> parseFile(const std::string& filename) {
	std::ifstream file(filename);
	std::string lineString;
	std::vector<std::string> returnVal;

	while (getline(file, lineString)) {
		returnVal.push_back(lineString);
	}

	file.close();
	return returnVal;
}

struct game {
	int id_;
	int maxR_;
	int maxG_;
	int maxB_;
};

int main() {
	
	std::vector<std::string> input = parseFile("input.txt");
	std::vector<game> validGames;
	int RED = 12;
	int GREEN = 13;
	int BLUE = 14;
	std::regex pattern("\\d");

	for (auto s : input) {
		for (int i=0; i<s.length(); i++) {
			std::string checkChar(1, s[i]);

		}
	}

	return 0;

}
