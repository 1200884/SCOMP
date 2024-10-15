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



void run_test(int x, int y, int expected, int exp_res)
{
    int  res; 
    int  v[3]={0x55555555,0x55555555,0x55555555}; 

    v[1]=y;     

	res = call_func(activate_bit,&v[1],x);
    
    TEST_ASSERT_EQUAL_INT(exp_res,res); 
    TEST_ASSERT_EQUAL_INT(expected,v[1]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[0]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[2]); 
    
}


void test_Zero()
{ 
    run_test(0,0,1,1); 
}
void test_One()
{ 
    run_test(0,1,1,0); 
}
void test_Four()
{ 
    run_test(4,1,0x11,1); 
}
void test_FourA()
{ 
    run_test(4,0x11,0x11,0); 
}
void test_Twelve()
{ 
    run_test(12,0x11,0x1011,1); 
}

void test_TwelveA()
{ 
    run_test(12,0x1011,0x1011,0); 
}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_Four);
    RUN_TEST(test_FourA);
    RUN_TEST(test_Twelve);
    RUN_TEST(test_TwelveA);
    return UNITY_END();  

  } 






