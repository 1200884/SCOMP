#include <string.h>  
#include "../../unity.h"
#include "asm.h" 

char call_func(char (*f)()); 
 
 extern int num; 
 extern int wall1; 
 extern int wall2; 

void setUp(void) {
    // set stuff up here
     
      wall1=0x12345678;  
      wall2=0x12345678;  
       
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, char expected)
{

    char result; 
    num=x; 
    result=call_func(check_num); 

    
    TEST_ASSERT_EQUAL_INT8(expected,result); 
    TEST_ASSERT_EQUAL_INT(x,num); 
    TEST_ASSERT_EQUAL_INT(0x12345678,wall1); 
    TEST_ASSERT_EQUAL_INT(0x12345678,wall2); 
    
}

void test_Zero()
{ 
    run_test(0, 3); 
}

void test_One()
{ 
    run_test(1, 4); 
}

void test_Two()
{ 
    run_test(2, 3); 
}


void test_MinusA()
{ 
    run_test( -1, 2); 
}

void test_MinusB()
{ 
    run_test( -10, 1); 
}

void test_Big()
{ 
   run_test(0xffffffff,  2); 
}

void test_Big2()
{ 
   run_test(0xfffffffe,  1); 

}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_Two);
    RUN_TEST(test_MinusA);
    RUN_TEST(test_MinusB);
    RUN_TEST(test_Big);
    RUN_TEST(test_Big2);
    return UNITY_END();  

  } 






