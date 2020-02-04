#include<iostream>
#include<fstream>
#include<cstdlib>
#include"bigint.hpp"

int main() {
	std::ifstream file("data1-2.txt");
	if (!file) {
		std::cerr << "Failed to open file, Exiting.";
		exit(1);
	}
	else {
		bigint biOne;
		bigint biTwo;
		bigint result;
		while (!file.eof()) {
			if (file.eof()) break;
			file >> biOne;
			if (file.eof()) break;
			file >> biTwo;
			std::cout << "Numbers to be Multiplied\n";
			std::cout << biOne << '\n' << biTwo << '\n';
			result = biOne * biTwo;
			std::cout << "This is the Product: \n";
			std::cout << result;
		}
		file.close();
	}

}
