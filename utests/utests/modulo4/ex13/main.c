#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(int x, int y), int x, int y );  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int y, int exp_l, int exp_r)
{
    int  resl; 
    int  resr; 

	resl = call_func(rotate_left,x,y);
        TEST_ASSERT_EQUAL_INT(exp_l,resl); 

	resr = call_func(rotate_right,x,y);
        TEST_ASSERT_EQUAL_INT(exp_r,resr); 
    
}


void test_Zero()
{ 
    run_test(0,0,0,0); 
}
void test_ZeroB()
{ 
    run_test(0,5,0,0); 
}
void test_MinusOne()
{ 
    run_test(-1,20,-1,-1); 
}
void test_One()
{ 
    run_test(1,2,4,0x40000000); 
}
void test_Two()
{ 
    run_test(7,4,0x70,0x70000000); 
}
void test_Five()
{ 
    run_test(0x55555555,1,0xaaaaaaaa,0xaaaaaaaa); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_ZeroB);
    RUN_TEST(test_MinusOne);
    RUN_TEST(test_One);
    RUN_TEST(test_Two);
    RUN_TEST(test_Five);
    return UNITY_END();  

  } 






