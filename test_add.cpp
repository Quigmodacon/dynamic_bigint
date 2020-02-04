// bigint Test Program
//
// Tests:  int constructor, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(56);
      bigint right(5);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == 56);
      assert(right == 5);
      assert(result == 61);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(10000);
      bigint right(35000);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == 10000);
      assert(right == 35000);
      assert(result == 45000);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1000000000000");
      bigint right(5);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == "1000000000000");
      assert(right == 5);
      assert(result == "1000000000005");
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("100000000000000000000000000000000000000000000000000");
      bigint right("100000000000000000000000000000000000000000000000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == "100000000000000000000000000000000000000000000000000");
      assert(right == "100000000000000000000000000000000000000000000000000");
      assert(result == "200000000000000000000000000000000000000000000000000");
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(99294);
      bigint right(99589);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == 99294);
      assert(right == 99589);
      assert(result == 198883);
    }
    //Add test cases as needed.
    
    
    std::cout << "Done with testing addition." << std::endl;
}

