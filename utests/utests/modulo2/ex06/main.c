#include <string.h>  
#include "../../unity.h"
#include "asm.h" 

 short call_func(short (*f)()); 
 
 extern char byte1; 
 extern char byte2; 
 extern char wall1; 
 extern char wall2; 
 extern char wall3; 

void setUp(void) {
    // set stuff up here
     
      wall1=0x78;  
      wall2=0x78;  
      wall3=0x78;  
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(char x, char y, short expected)
{

    short result; 
    byte1=x; 
    byte2=y; 
    result=call_func(concatBytes); 

    
    TEST_ASSERT_EQUAL_INT16(expected,result); 
    TEST_ASSERT_EQUAL_INT8(x,byte1); 
    TEST_ASSERT_EQUAL_INT8(y,byte2); 
    TEST_ASSERT_EQUAL_INT8(0x78,wall1); 
    TEST_ASSERT_EQUAL_INT8(0x78,wall2); 
    TEST_ASSERT_EQUAL_INT8(0x78,wall3); 
    
}

void test_Zero()
{ 
    run_test(0, 0, 0); 

}

void test_OneA()
{ 
    run_test(0, 1, 256); 

}

void test_OneB()
{ 
    run_test(1, 0, 1); 

}

void test_Minus()
{ 
    run_test( -1, -1, -1); 

}

void test_Big()
{ 
   run_test(50, 50, 0x3232); 

}

void test_Big2()
{ 
   run_test( 0, 50, 0x3200); 

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






