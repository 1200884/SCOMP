#include <string.h>  
#include "../../unity.h"
#include "asm.h" 



void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int y , int expected )
//  base, exponent 
{
    int vec[3];

    

    // setup 
        vec[0]=0x55555555;
        vec[2]=0x55555555;
	vec[1]=x;    
	power_ref(&vec[1],y);
    
    TEST_ASSERT_EQUAL_INT_MESSAGE(0x55555555, vec[0],"Sentinel 1");    // check sentinel 
    TEST_ASSERT_EQUAL_INT_MESSAGE(0x55555555, vec[2],"Sentinel 2");    // check sentinel 
    TEST_ASSERT_EQUAL_INT(expected, vec[1]);    // check result 
   
    
}


void test_Zero()
{ 
    run_test(3,0,1); 
}
void test_Minus()
{ 
    run_test(3,-3,0); 
}
void test_One()
{ 
    run_test(2,1,2); 
}

void test_Minus3()
{ 
    run_test(-3,3,-27); 
}
void test_Plus3()
{ 
    run_test(3,3,27); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_Minus);
    RUN_TEST(test_One);
    RUN_TEST(test_Minus3);
    RUN_TEST(test_Plus3);
    return UNITY_END();  

  } 






