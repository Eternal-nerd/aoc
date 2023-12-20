#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

std::string getString(char x) {
    std::string s(1, x);
    return s;
}

std::vector<long long> splitUp(const std::string& s) {
	std::vector<long long> returnVal;
	std::string tempNum = "";
	bool first = true;
	for (char c : s) {
		if (c==' ' && !tempNum.empty()) {
			if (first) {
				first=false;
				tempNum.clear();
			}
			else {
				//returnVal.push_back(stoi(tempNum));
			}
			//tempNum.clear();
		}
		if (c!=' ') {
			tempNum += c;
		}
	}
	if (!tempNum.empty()) {
		returnVal.push_back(stoi(tempNum));
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

	long product = 1;
	std::vector<long long> times = splitUp(input_vec[0]);
	
	std::vector<long long> distances = splitUp(input_vec[1]);
	std::cout << times.size();

	return 0;

	for (int i=0; i<times.size(); i++) {
		int count = 0;
		for (long long j=0; j<times[i]; j++) {
			long long distance = j*(times[i]-j);
			if (distance > distances[i]) {
				count++;
			}
		}
		product*=count;
	}
	
	std::cout << "Product: " << product << std::endl;
    return 0;
}
