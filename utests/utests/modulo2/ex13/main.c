#include <string.h>  
#include "../../unity.h"
#include "asm.h" 

 int call_func(int (*f)()); 
 
 extern int base; 
 extern int height;  
 extern int wall1; 
 extern int wall2; 
 extern int wall3; 

void setUp(void) {
    // set stuff up here
     
      wall1=0x12345678;  
      wall2=0x12345678;  
      wall3=0x12345678;  
       
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int y, int expected)
{

    int result; 
    base=x; 
    height=y; 
    result=call_func(getArea); 

    
    TEST_ASSERT_EQUAL_INT(expected,result); 
    TEST_ASSERT_EQUAL_INT(x,base); 
    TEST_ASSERT_EQUAL_INT(y,height); 
    TEST_ASSERT_EQUAL_INT(0x12345678,wall1); 
    TEST_ASSERT_EQUAL_INT(0x12345678,wall2); 
    TEST_ASSERT_EQUAL_INT(0x12345678,wall3); 
    
}

void test_Zero()
{ 
    run_test(0, 0, 0); 
}

void test_OneA()
{ 
    run_test(1, 2, 1); 
}

void test_OneB()
{ 
    run_test(2, 2, 2); 
}

void test_OneC()
{ 
    run_test( 800, 800, 320000); 
}

void test_MinusA()
{ 
    run_test( 3, 5, 7); 
}

void test_MinusB()
{ 
    run_test( 1000, 1000, 500000); 
}

void test_Big()
{ 
   run_test(5000, 5000, 12500000); 

}

void test_Big2()
{ 
   run_test(50000, 50, 1250000); 

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






