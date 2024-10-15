#include <string.h>  
#include "../../unity.h"
#include "asm.h" 



void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(char str_in[], char  expected[])
{
    char vec[100];


    // setup 
      
	memset(vec, 0x55, sizeof(vec));
	strcpy(vec+1,str_in);   // bad programming  
	capitalize(vec+1); 
    
    TEST_ASSERT_EQUAL_CHAR_MESSAGE(0x55, vec[0],"Sentinel 1");    // check sentinel 
    TEST_ASSERT_EQUAL_CHAR_MESSAGE(0x55, vec[strlen(str_in)+2],"Sentinel 2");    // check sentinel 
    TEST_ASSERT_EQUAL_STRING(expected,vec+1);    // check result 

    
}


void test_Null()
{ 
    run_test("",""); 
}
void test_One()
{ 
    run_test("v","V"); 
}
void test_Hey()
{ 
    run_test("hey","Hey"); 
}
void test_Hello()
{ 
    run_test("hello world\n","Hello World\n"); 
}
void test_One_Zero1()
{ 
    run_test("One zero 8","One Zero 8"); 
} 
void test_One_Zero2()
{ 
    run_test("One zero e","One Zero E"); 
} 

void test_Two()
{ 
    run_test("two 2t","Two 2t"); 
} 

void test_Case1()
{ 
    run_test("The number must be saved ","The Number Must Be Saved "); 
} 

void test_Case2()
{ 
    run_test("The maximum value of this CYCLE","The Maximum Value Of This CYCLE"); 
} 


int main()
  { 
    UNITY_BEGIN();
    RUN_TEST(test_Null);
    RUN_TEST(test_One);
    RUN_TEST(test_Hey);
    RUN_TEST(test_Hello);
    RUN_TEST(test_One_Zero1);
    RUN_TEST(test_One_Zero2);
    RUN_TEST(test_Two);
    RUN_TEST(test_Case1);
    RUN_TEST(test_Case2);
    return UNITY_END();  
  } 






