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
