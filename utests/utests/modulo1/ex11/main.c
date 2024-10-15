#include <string.h>  
#include "../../unity.h"
#include "asm.h" 



void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(char str_in[], int  expected)
{
    char vec[100];

    int res;  

    // setup 
      
	memset(vec, 0x55, sizeof(vec));
	strcpy(vec+1,str_in);   // bad programming  
	res=palindrome(vec+1); 
    
    TEST_ASSERT_EQUAL_CHAR_MESSAGE(0x55, vec[0],"Sentinel 1");    // check sentinel 
    TEST_ASSERT_EQUAL_CHAR_MESSAGE(0x55, vec[strlen(str_in)+2],"Sentinel 2");    // check sentinel 
    TEST_ASSERT_EQUAL_INT(expected,res );    // check result 
    TEST_ASSERT_EQUAL_STRING(str_in,vec+1);     // check if string has changed 

    
}


void test_Null()
{ 
    run_test((char*)"",0); 
}
void test_One()
{ 
    run_test((char*)"v",1); 
}
void test_Ab()
{ 
    run_test((char*)"aaabab",0); 
}
void test_Zero()
{ 
    run_test((char*)"00001",0); 
}
void test_Case1()
{ 
    run_test((char*)"Never odd or even.",1); 
} 
void test_Case2()
{ 
    run_test((char*)"A man a plan a canal Panama.",1); 
} 
void test_Case3()
{ 
    run_test((char*)"Gateman sees name, garageman sees name tag",1); 
} 


int main()
  { 
    UNITY_BEGIN();
    RUN_TEST(test_Null);
    RUN_TEST(test_One);
    RUN_TEST(test_Ab);
    RUN_TEST(test_Zero);
    RUN_TEST(test_Case1);
    RUN_TEST(test_Case2);
    RUN_TEST(test_Case3);
    return UNITY_END();  
  } 






