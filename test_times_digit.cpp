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
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == 0);  
    }

	{
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 3);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == 6);  
    }

	{
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(3);

        // Verify
        assert(bi == 9);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(4);
		std::cout << bi;
        // Verify
        assert(bi == 12);  
    }

	{
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(5);

        // Verify
        assert(bi == 15);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(6);

        // Verify
        assert(bi == 18);  
    }

	{
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(7);

        // Verify
        assert(bi == 21);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(8);

        // Verify
        assert(bi == 24);  
    }

	{
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 27);  
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(675);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 6075);  
    }

	{
        //------------------------------------------------------
        // Setup fixture
        bigint bi(75849);

        // Test 
        bi = bi.timesDigit(7);

        // Verify
        assert(bi == 530943);  
    }

    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;
}
