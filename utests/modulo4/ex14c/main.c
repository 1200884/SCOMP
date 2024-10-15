#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


void call_func ( void (*f)(int *p, int x), int *p, int x );  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int y, int expected )
{
    int  v[3]={0x55555555,0x55555555,0x55555555}; 

    v[1]=y;     

	call_func(activate_2bits,&v[1],x);
    
    TEST_ASSERT_EQUAL_INT(expected,v[1]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[0]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[2]); 
    
}


void test_Zero()
{ 
    run_test(0,0,0x80000001); 
}
void test_One()
{ 
    run_test(4,0x80000001,0x88000011); 
}
void test_Four()
{ 
    run_test(4,0x88000011,0x88000011); 
}
void test_Twelve()
{ 
    run_test(12,0x88000011,0x88081011); 
}
void test_TwelveA()
{ 
    run_test(12,0x88081011,0x88081011); 
}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_Four);
    RUN_TEST(test_Twelve);
    RUN_TEST(test_TwelveA);
    return UNITY_END();  

  } 






