#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


void call_func ( void (*f)(int *p), int *p );  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x,  int expected)
{
    int  v[3]={0x55555555,0x55555555,0x55555555}; 

    v[1]=x;     

    call_func(changes,&v[1]);
    
    TEST_ASSERT_EQUAL_INT(expected,v[1]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[0]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[2]); 
    
}


void test_Zero()
{ 
    run_test(0,0); 
}
void test_One()
{ 
    run_test(-1,0xff0fffff); 
}
void test_Two()
{ 
    run_test(0xff,0xff); 
}
void test_Three()
{ 
    run_test(0xff0fffff,0xff0fffff); 
}
void test_Four()
{ 
    run_test(0xff8ff0ff,0xff7ff0ff); 
}
void test_Five()
{ 
    run_test(0xff7fffff,0xff7fffff); 
}
void test_Six()
{ 
    run_test(0x00700000,0x00700000); 
}
void test_Seven()
{ 
    run_test(0x00800000,0x00700000); 
}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_Two);
    RUN_TEST(test_Three);
    RUN_TEST(test_Four);
    RUN_TEST(test_Five);
    RUN_TEST(test_Six);
    RUN_TEST(test_Seven);
    return UNITY_END();  

  } 






