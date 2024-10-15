#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(int num), int num );  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int expected )
{
    int  res; 

    

    // setup 
	res = call_func(cube,x);
    
    TEST_ASSERT_EQUAL_INT(expected,res); 
    
}


void test_Zero()
{ 
    run_test(0,0); 
}
void test_One()
{ 
    run_test(1,1); 
}
void test_MinusOne()
{ 
    run_test(-1,-1); 
}
void test_Two()
{ 
    run_test(2,8); 
}

void test_MinusThree()
{ 
    run_test(-3,-27); 
}
void test_Five()
{ 
    run_test(5,125); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_MinusOne);
    RUN_TEST(test_Two);
    RUN_TEST(test_MinusThree);
    RUN_TEST(test_Five);
    return UNITY_END();  

  } 






