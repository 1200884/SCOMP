#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


void call_func ( void (*f)(void) );  
char * ptr1;  
char * ptr2; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(char * str, char * expected )
{
    char vec1[100];
    char vec2[100];

    

    // setup 
        memset(vec1, 0xaa, sizeof vec1);
        memset(vec2, 0xaa, sizeof vec2);
     
        ptr1=vec1+1; 	
        ptr2=vec2+1; 	
	strcpy(vec1+1,str);  // bad practice  
	call_func(str_copy_porto2);
    
    TEST_ASSERT_EQUAL_CHAR(0xaa, vec1[strlen(str)+2]);    // check sentinel 
    TEST_ASSERT_EQUAL_CHAR(0xaa, vec1[0]);    // check sentinel 
    TEST_ASSERT_EQUAL_PTR(vec1+1,ptr1);  
    TEST_ASSERT_EQUAL_CHAR(0xaa, vec2[strlen(str)+2]);    // check sentinel 
    TEST_ASSERT_EQUAL_CHAR(0xaa, vec2[0]);    // check sentinel 
    TEST_ASSERT_EQUAL_PTR(vec2+1,ptr2);  
    TEST_ASSERT_EQUAL_STRING(expected,ptr2); 
    
}


void test_hey()
{ 
    run_test("hey","hey"); 
}
void test_hello()
{ 
    run_test("Hello world!\n","Hello world!\n"); 
}
void test_One_v()
{ 
    run_test("One v","One b"); 
}
void test_One_b()
{ 
    run_test("One b","One b"); 
}
void test_Two_v()
{ 
    run_test("Two vV","Two bB"); 
}
void test_Two_B()
{ 
    run_test("Two BB","Two BB"); 
}
void test_Three_v()
{ 
    run_test("Three vVv","Three bBb"); 
}
void test_NullString()
{ 
    run_test("",""); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_hey);
    RUN_TEST(test_hello);
    RUN_TEST(test_One_v);
    RUN_TEST(test_One_b);
    RUN_TEST(test_Two_v);
    RUN_TEST(test_Two_B);
    RUN_TEST(test_Three_v);
    RUN_TEST(test_NullString);
    return UNITY_END();  

  } 






