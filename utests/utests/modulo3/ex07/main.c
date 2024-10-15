#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(void) );  
char * ptr1;  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(char * str, int expected , char * str_expected)
{
    char vec[100];
    int  res; 

    

    // setup 
        memset(vec, 0xaa, sizeof vec);
     
        ptr1=vec+1; 	
	strcpy(vec+1,str);  // bad practice  
	res = call_func(decrypt);
    
    TEST_ASSERT_EQUAL_CHAR(0xaa, vec[strlen(str)+2]);    // check sentinel 
    TEST_ASSERT_EQUAL_CHAR(0xaa, vec[0]);    // check sentinel 
    TEST_ASSERT_EQUAL_STRING(str_expected,vec+1);  
    TEST_ASSERT_EQUAL_INT(expected,res); 
    
}


void test_None()
{ 
    run_test("",0,""); 
}
void test_Hex()
{ 
    run_test("jgz",3,"hex"); 
}
void test_Spaces() 
{ 
    run_test("     ",0,"     "); 
}
void test_Abba()
{ 
    run_test(" adda ",2," abba "); 
}

void test_ABBA()
{ 
    run_test(" CDDC ",4," ABBA "); 
}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_None);
    RUN_TEST(test_Hex);
    RUN_TEST(test_Spaces);
    RUN_TEST(test_Abba);
    RUN_TEST(test_ABBA);
    return UNITY_END();  

  } 






