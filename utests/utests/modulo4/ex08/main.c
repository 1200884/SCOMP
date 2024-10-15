#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(int a, int *b, int c), int a, int *b , int c  );  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int y, int z, int expected)
{
    int  res; 
    int  v[3]={0x55555555,0x55555555,0x55555555}; 

    v[1]=y;  

    // setup 
	res = call_func(calc,x,&v[1],z);
    
    TEST_ASSERT_EQUAL_INT(expected,res); 
    TEST_ASSERT_EQUAL_INT(y,v[1]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[0]); 
    TEST_ASSERT_EQUAL_INT(0x55555555,v[2]); 
    
}


void test_MinusTwo()
{ 
    run_test(0,0,0,-2); 
}
void test_MinusOne()
{ 
    run_test(1,2,1,-1); 
}
void test_MinusOneA()
{ 
    run_test(2,1,-1,-1); 
}
void test_MinusSix()
{ 
    run_test(2,1,4,-6); 
}
void test_Six()
{ 
    run_test(3,1,-4,6); 
}

int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_MinusTwo);
    RUN_TEST(test_MinusOne);
    RUN_TEST(test_MinusOneA);
    RUN_TEST(test_MinusSix);
    RUN_TEST(test_Six);
    return UNITY_END();  

  } 






