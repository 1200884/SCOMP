#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func( int (*f)());  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void run_test( int expected )
{
    int  res; 
    // setup 
	res = call_func(call_incr);
    
    TEST_ASSERT_EQUAL_INT(expected,res); 
}

void test_Lonely()                  /*  LOTS of things to improve !!!! */ 
{ 
    run_test(-48345); 
}

int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Lonely);
    return UNITY_END();  

  } 






