#include "bigint.hpp"
#include <iostream>
#include <cassert>
#include <fstream>

int main() {

		std::cout << "Enter a number, end it with a semicolon ';'\n";
		
		bigint bi;

		std::cin >> bi;
		bi.debugPrint(std::cout);
		std::cout << '\n' << '\n';
		std::cin >> bi;
		assert(bi == 70);
		bi.debugPrint(std::cout);

		std::ifstream file("data1-1.txt");
		if (!file.is_open())
			std::cout << "file unable to be opened \n";
		else {
			file >> bi;
			assert(bi == "10000000000000000000000000000000000345");
			file >> bi;
			assert(bi == "29979300000000000000000000000000067");
			file >> bi;
			assert(bi == "4208574289572473098273498723475");
			file >> bi;
			assert(bi == "28375039287459832728745982734509872340985729384750928734590827098752938723");
		   	file >> bi;
			assert(bi == "99999999");
			file >> bi;
			assert(bi == "99999999");	
		}
			

}
