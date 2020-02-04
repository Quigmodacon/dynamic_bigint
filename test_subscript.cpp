// bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }
    
    //Add test cases!!
	
    {
        // Setup
        bigint bi;

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 0); 
        assert(digit == 0);
    }

    {
        // Setup
        bigint bi(1234567890);

        // Test 
        int digit = bi[9];

        // Verify
        assert(bi    == 1234567890); 
        assert(digit == 1);
    }

    {
        // Setup
        bigint bi(10);

        // Test 
        int digit = bi[3];

        // Verify
        assert(bi    == 10); 
        assert(digit == -1);
    }

    std::cout << "Done testing subscript." << std::endl;
}

