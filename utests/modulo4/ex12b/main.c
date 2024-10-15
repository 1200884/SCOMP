#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(int x), int x );  

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
	res = call_func(count_bits_zero,x);
    
    TEST_ASSERT_EQUAL_INT(expected,res); 
    
}


void test_None()
{ 
    run_test(-1,0); 
}
void test_One()
{ 
    run_test(-2,1); 
}
void test_All()
{ 
    run_test(0,32); 
}
void test_Two()
{ 
    run_test(-6,2); 
}

void test_Three()
{ 
    run_test(3,30); 
}
void test_Sixteen()
{ 
    run_test(0xffff,16); 
}
void test_SixteenA()
{ 
    run_test(0xffff0000,16); 
}
void test_SixteenB()
{ 
    run_test(0xf0f0f0f0,16); 
}
void test_SixteenC()
{ 
    run_test(0x0f0f0f0f,16); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_None);
    RUN_TEST(test_One);
    RUN_TEST(test_All);
    RUN_TEST(test_Two);
    RUN_TEST(test_Three);
    RUN_TEST(test_Sixteen);
    RUN_TEST(test_SixteenA);
    RUN_TEST(test_SixteenB);
    RUN_TEST(test_SixteenC);
    return UNITY_END();  

  } 






