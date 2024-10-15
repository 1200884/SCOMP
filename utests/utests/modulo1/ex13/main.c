#include <string.h>  
#include "../../unity.h"
#include "asm.h" 



void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(char c, char str_in[], int expected, int  exp_vec[])
{
    char vec[100];

    int  vec_out[100]; 

    // setup 
      
	memset(vec, 0x55, sizeof(vec));
    memset(vec_out, 0, sizeof(vec_out));
	strcpy(vec+1,str_in);   // bad programming  
	int r; 
	r=where_is(vec+1,c,vec_out+1);
 
    
    TEST_ASSERT_EQUAL_CHAR_MESSAGE(0x55, vec[0],"Sentinel 1");    // check sentinel 
    TEST_ASSERT_EQUAL_CHAR_MESSAGE(0x55, vec[strlen(str_in)+2],"Sentinel 2");    // check sentinel
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, vec_out[0],"Sentinel 1 ints");    // check sentinel 
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, vec_out[r+1],"Sentinel 2 intd");    // check sentinel

    TEST_ASSERT_EQUAL_INT(expected,r);    // check result 
    if (r>0)
        TEST_ASSERT_EQUAL_INT_ARRAY(exp_vec,vec_out+1,r);

    
}


void test_Null()
{ 
    run_test('c',"",0,(int[]){0}); 
}
void test_One()
{ 
    run_test('c'," c",1,(int[]){1});
}
void test_Three()
{ 
    run_test('c',"ccc",3,(int[]){0,1,2}); 
}

void test_Three_Interval()
{ 
    run_test('c'," c c c",3,(int[]){1,3,5}); 
}

void test_Three_Middle()
{ 
    run_test('x',"CxCxCxCCCCCCCCCCC",3,(int[]){1,3,5}); 
}



int main()
  { 
    UNITY_BEGIN();
    RUN_TEST(test_Null);
    RUN_TEST(test_One);
    RUN_TEST(test_Three);
    RUN_TEST(test_Three_Interval);
    RUN_TEST(test_Three_Middle);
    return UNITY_END();  
  } 






