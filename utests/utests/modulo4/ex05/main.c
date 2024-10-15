#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(int *p, int x), int *p, int x );  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int y, int expected, int exp_inc)
{
    int  res; 
    int  v[3]={0x55555555,0x55555555,0x55555555}; 

    v[1]=y;     

	res = call_func(inc_and_square,&v[1],x);
    
    TEST_ASSERT_EQUAL_INT(expected,res); 
    TEST_ASSERT_EQUAL_INT(exp_inc,v[1]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[0]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[2]); 
    
}


void test_Zero()
{ 
    run_test(0,0,0,1); 
}
void test_One()
{ 
    run_test(0,1,0,2); 
}
void test_MinusOne()
{ 
    run_test(-1,-2,1,-1); 
}
void test_MinusOneB()
{ 
    run_test(-2,-1,4,0); 
}
void test_Two()
{ 
    run_test(4,2,16,3); 
}

void test_Three()
{ 
    run_test(3,3,9,4); 
}
void test_Five()
{ 
    run_test(5,5,25,6); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_MinusOne);
    RUN_TEST(test_MinusOneB);
    RUN_TEST(test_Two);
    RUN_TEST(test_Three);
    RUN_TEST(test_Five);
    return UNITY_END();  

  } 






