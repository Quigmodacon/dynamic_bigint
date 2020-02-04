// Big Int ADT
// Jonathan Hansen
// 2/2/2019

#include <iostream>
#include "bigint.hpp"

// Default constructor
bigint::bigint() {
	for (int i = 1; i < CAPACITY; i++) {
		big[i] = -1;
	}
	big[0] = 0;
}

// Integer constructor
bigint::bigint(int number) {
	int tmp = 0;
	int watcher = number;
	for (int i = 0; i < CAPACITY; i++) {
		if (number != 0 && watcher != 0) {
			tmp = watcher % 10;
			big[i] = tmp;
			watcher = watcher / 10;
		}
		else if (number == 0 && tmp != -1){
			big[0] = 0;
			tmp = -1;
		}
		else {
			big[i] = -1;
		}
	}
}

// Const char array constructor
bigint::bigint(const char number[]) {
	int index = 0;
	while (number[index] != 0) {
		index++;
	}
	for (int i = 0; i < index; i++) {
		big[i] = number[(index - 1) - i] - '0';
	}
	for (int i = index; i < CAPACITY; i++) {
		big[i] = -1;
	}
}

// Gets a specific index
int bigint::getIndex(int index) const {
	return big[index];
}

// Prints info for debugging
void bigint::debugPrint(std::ostream& out) const {
	for (int i = CAPACITY - 1; i >= 0; i--) {
		out << big[i] << "|";
	}
}

// Overloads == to allow equivalency checking
bool bigint::operator==(const bigint rhs) const {
	for (int i = 0; i < CAPACITY; i++) {
		if (big[i] != rhs.big[i])
			return false;
	}
	return true;
}

// Overloads addition
bigint bigint::operator+ (const bigint& rhs) const {
	int carry = 0;
	int tmp = 0;
	int storedValue = 0;
	bigint result;
	int index = 0;
	while (big[index] != -1 && rhs[index] != -1) {
		tmp = big[index] + rhs[index] + carry;
		carry = tmp / 10;
		storedValue = tmp % 10;
		result.big[index] = storedValue;
		++index;
	}	
	if (big[index] != -1) {
		while (big[index] != -1) {
			tmp = big[index] + carry;
			carry = tmp / 10;
			storedValue = tmp % 10;
			result.big[index] = storedValue;
			++index;
		}		
	}
	else if (rhs.big[index] != -1) {
		while (rhs.big[index] != -1) {
			tmp = rhs.big[index] + carry;
			carry = tmp / 10;
			storedValue = tmp % 10;
			result.big[index] = storedValue;
			++index;
		}		
	}
	if (carry != 0) {
		result.big[index] = carry;
	}
	return result;
}

// Overload [] to allow getting a specififc place.
int bigint::operator[](const int index) const {
	return big[index];
}

// overloads << to allow standard printing syntax
std::ostream& operator<<(std::ostream& out, const bigint& rhs) {
	bool first_nonzero_found = false;
	for (int i = CAPACITY - 1; i >= 0; i--) {
		if (rhs.big[i] != -1) {
			if (rhs.big[i] != 0 || first_nonzero_found) {
				first_nonzero_found = true;	
				out << rhs.big[i];
			}
			if (i == 0 && rhs.big[0] == 0 && !first_nonzero_found) {
				out << rhs.big[0];
			}
		}
	}
//	out << std::endl;
	return out;
}

// Overloads >> to allow input
std::istream& operator>>(std::istream& in, bigint& rhs) {
	for (int i = 0; i < CAPACITY; ++i) {
		rhs.big[i] = -1;
	}
	bigint temp;
	//temp.debugPrint(std::cout); std::cout << '\n'; // Remove after testing;
	int index = 0;
	char ch;
	in >> ch;
	//std::cout << ch << '\n'; // To remove
	while (ch != ';' && !in.eof()) {
		temp.big[index] = ch - '0';
		in >> ch;
		++index;
	//	temp.debugPrint(std::cout); std::cout << '\n';// Remove after testing;
	//	std::cout << ch << '\n'; // to remove

	}
	int i = 0;
	while (index >= 0) {
		rhs.big[index - 1] = temp.big[i];
		++i;
		--index;
	//	rhs.debugPrint(std::cout); std::cout << '\n'; //To Remove
	}
	return in;
}

// Multiplies by single digit
bigint bigint::timesDigit(int number) const {
	bigint result;
	int carry = 0;
	int tmp = 0;
	int index = 0;
	while (index < CAPACITY && big[index] != -1) {
		tmp = (big[index] * number) + carry;
		result.big[index] = tmp % 10; 
		carry = tmp / 10;
		++index;
	}
	if (index < CAPACITY && carry != 0) {
		result.big[index] = carry;
	}
	return result;
}

// Multiplies by 10 n times
bigint bigint::times10(int n) const {
	bigint result;
	bigint tmp;
	tmp = *this;
	if (n != 0) {
		for (int j = 0; j < n; ++j) {
			for (int i = 1; i < CAPACITY; ++i) {
				result.big[i] = tmp.big[i - 1];
			}
			tmp = result;
		}
	}
	else 
		result = operator+(0);
	return result;
}

// Multiplies 2 bigints
bigint bigint::operator*(const bigint& rhs) const {
	bigint tmp;
	bigint product;
	int index = 0;
	while (index < CAPACITY && rhs[index] != -1) {
		tmp = timesDigit(rhs[index]);
		product = product + tmp.times10(index);
		++index;
	}
	return product;
}
