#include <string.h>  
#include "../../unity.h"
#include "asm.h" 

 int call_func(int (*f)()); 
 
 extern short desired; 
 extern short current; 
 extern short wall1; 
 extern short wall2; 
 extern short wall3; 

void setUp(void) {
    // set stuff up here
     
      wall1=0x5678;  
      wall2=0x5678;  
      wall3=0x5678;  
       
       
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(short x, short y, int expected)
{

    int result; 
    current=x; 
    desired=y; 
    result=call_func(needed_time); 

    
    TEST_ASSERT_EQUAL_INT(expected,result); 
    TEST_ASSERT_EQUAL_INT16(x,current); 
    TEST_ASSERT_EQUAL_INT16(y,desired); 
    TEST_ASSERT_EQUAL_INT16(0x5678,wall1); 
    TEST_ASSERT_EQUAL_INT16(0x5678,wall2); 
    TEST_ASSERT_EQUAL_INT16(0x5678,wall3); 
    
}

void test_Zero()
{ 
    run_test(0, 0, 0); 
}

void test_OneA()
{ 
    run_test(0, 10, 20*60); 
}

void test_OneB()
{ 
    run_test(2, 3, 2*60); 
}

void test_OneC()
{ 
    run_test( -2, -1, 2*60); 
}

void test_MinusA()
{ 
    run_test( 5, 3, 6*60); 
}

void test_MinusB()
{ 
    run_test( 5, -5, 30*60); 
}

void test_Big()
{ 
   run_test(50, 100, 100*60); 

}

void test_Big2()
{ 
   run_test(5, 55, 100*60); 

}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_OneA);
    RUN_TEST(test_OneB);
    RUN_TEST(test_OneC);
    RUN_TEST(test_MinusA);
    RUN_TEST(test_MinusB);
    RUN_TEST(test_Big);
    RUN_TEST(test_Big2);
    return UNITY_END();  

  } 






