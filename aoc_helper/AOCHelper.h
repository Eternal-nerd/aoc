#pragma once
#include <string>
#include <vector>

class AOCHelper {	
public:
	AOCHelper(const std::string& inputFilename);
	void printFirst();

private:
	std::vector<std::string> input;

	std::vector<std::string> parseFile(const std::string& filename);
};

