//==============================================================================
// Basics for openning a file for milestone 2 of Project 1.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-1.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
        exit(1);
    }
	bigint biOne;
	bigint biTwo;
	bigint result;
    while (!in.eof()) {
		in >> biOne;
		in >> biTwo;
		std::cout << "Numbers to be added: " << '\n';
		std::cout << biOne << '\n' << biTwo << '\n';
		result = biOne + biTwo;
		std::cout << "This is the sum: " << '\n';
		std::cout << result;
	}
 
    in.close();
    return 0;
}

