#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


void  call_func ( void  (*f)(void) );  
char * ptr1; 
char * ptr2; 
char * ptr3; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test( char * str1, char * str2, char * expected  )
{
    char vec[100];


    // setup 
        memset(vec, 0x55, sizeof vec);
    
	ptr1=str1;  
	ptr2=str2;  
        ptr3=vec+1;  		
	call_func(str_cat);
    
    TEST_ASSERT_EQUAL_INT8(0x55, vec[strlen(str1)+strlen(str2)+2]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT8(0x55, vec[0]);    // check sentinel  
    TEST_ASSERT_EQUAL_STRING(expected,vec+1);  
    TEST_ASSERT_EQUAL_PTR(vec+1, ptr3);    // check ptr  
    TEST_ASSERT_EQUAL_PTR(str1, ptr1);    // check ptr  
    TEST_ASSERT_EQUAL_PTR(str2, ptr2);    // check ptr  
    
}


void test_NullVector()
{ 
    run_test("","",""); 
}
void test_One()
{ 
    run_test("O","ne","One"); 
}
void test_Zero()
{ 
    run_test("Zero","","Zero"); 
}
void test_Zero2()
{ 
    run_test("","Zero","Zero"); 
}
void test_Zero3()
{ 
    run_test("0000","Zero0000","0000Zero0000"); 
}

int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_NullVector);
    RUN_TEST(test_One);
    RUN_TEST(test_Zero);
    RUN_TEST(test_Zero2);
    RUN_TEST(test_Zero3);
    return UNITY_END();  

  } 






