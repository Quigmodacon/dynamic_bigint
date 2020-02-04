// Big Int ADT
// Jonathan Hansen
// 2/2/2019

#ifndef CS2_BIGINT_HPP
#define CS2_BIGINT_HPP

#include <iostream>

const int CAPACITY = 300;

class bigint {
public:
           bigint     ();
           bigint     (int);
           bigint     (const char[]);
	int    getIndex   (int) const;
    void   debugPrint (std::ostream&) const;
    bool   operator== (bigint) const;
	bigint operator+  (const bigint&) const;
	int    operator[] (const int) const;
	bigint operator*  (const bigint&) const;
	bigint timesDigit(int) const;
	bigint times10(int) const;

	friend std::ostream& operator<<(std::ostream&, const bigint&);
	friend std::istream& operator>>(std::istream&, bigint&);
private:
    int big[CAPACITY];
};

#endif
