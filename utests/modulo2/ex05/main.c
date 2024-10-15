#include <string.h>  
#include "../../unity.h"
#include "asm.h" 

 short call_func(short (*f)()); 
 
 extern short s; 
 extern short wall1; 
 extern short wall2;  

void setUp(void) {
    // set stuff up here
     
      wall1=0x55aa;  
      wall2=0x55aa;  
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(short sh, short expected)
{

    short result; 
    s=sh; 
    result=call_func(swapBytes); 

    
    TEST_ASSERT_EQUAL_INT16(expected,result); 
    TEST_ASSERT_EQUAL_INT16(sh,s); 
    TEST_ASSERT_EQUAL_INT16(0x55aa,wall1); 
    TEST_ASSERT_EQUAL_INT16(0x55aa,wall2); 
    
}

void test_Zero()
{ 
    run_test(0, 0); 

}

void test_OneA()
{ 
    run_test( 1, 256); 

}

void test_OneB()
{ 
    run_test( 256, 1); 

}

void test_Minus()
{ 
    run_test( -1, -1); 

}

void test_Big()
{ 
   run_test( 0xff, 0xff00); 

}

void test_Big2()
{ 
    run_test( 0xff00, 0xff); 

}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_OneA);
    RUN_TEST(test_OneB);
    RUN_TEST(test_Minus);
    RUN_TEST(test_Big);
    RUN_TEST(test_Big2);
    return UNITY_END();  

  } 






