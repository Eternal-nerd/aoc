#include "AOCHelper.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>
#include <fstream>
#include <iostream>

void AOCHelper::printFirst() {
	std::cout << input[0] << std::endl;
}

std::vector<std::string> AOCHelper::splitOn(const std::string& s, char delim) {

	std::vector<std::string> return_val;
	std::string temp_str;

	for (int i=0; i<s.length(); i++) {
		std::cout << s[i] << std::endl;
	}

	return return_val;
}

AOCHelper::AOCHelper(const std::string& inputFilename) {
	input = parseFile(inputFilename);
}

std::vector<std::string> AOCHelper::parseFile(const std::string& filename) {
	std::ifstream file(filename);
	std::string lineString;
	std::vector<std::string> returnVal;

	while (getline(file, lineString)) {
		returnVal.push_back(lineString);
	}

	file.close();
	return returnVal;
}
