// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(0);

        // Verify
        assert(bi == 3);
    }
   
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(999);

        // Test 
        bi = bi.times10(2);

        // Verify
        assert(bi == 99900);
    }	

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1234567890);

        // Test 
        bi = bi.times10(10);

        // Verify
        assert(bi == "12345678900000000000");
    }

	{
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(100);

        // Verify
        assert(bi == "30000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    }
   
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(6754);

        // Test 
        bi = bi.times10(23);

        // Verify
        assert(bi == "675400000000000000000000000"); 
    }	

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(2);

        // Verify
        assert(bi == 300); 
    }


    std::cout << "Done testing times_10" << std::endl;
}

