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
	res = call_func(sum_n,x);
    
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
    run_test(-1,0); 
}
void test_Two()
{ 
    run_test(2,3); 
}

void test_Three()
{ 
    run_test(3,6); 
}
void test_Five()
{ 
    run_test(5,15); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_MinusOne);
    RUN_TEST(test_Two);
    RUN_TEST(test_Three);
    RUN_TEST(test_Five);
    return UNITY_END();  

  } 






