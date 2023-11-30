#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

	std::ifstream file("input.txt");
	std::string lineString;
	std::vector<std::string> fileContents;
	int i = 0;

	while (getline(file, lineString)) {
		fileContents.push_back(lineString);
		std::cout << fileContents[i] << std::endl;
		i++;
	}

	file.close();

	return 0;

}
