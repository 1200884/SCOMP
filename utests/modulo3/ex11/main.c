#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(void) );  
long * ptrvec;  
int num; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(long * vec, int in_num, int  expected )
{
    long vec1[100];

    int res;

    // setup 
        memset(vec1, 0x55, sizeof vec1);
     
        ptrvec=vec1+1; 	
	memcpy(vec1+1,vec,in_num*sizeof(long));  //   
        num = in_num; 
	res=call_func(vec_greater20);
    
    TEST_ASSERT_EQUAL_INT(0x5555555555555555, vec1[in_num+1]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT(0x5555555555555555, vec1[0]);    // check sentinel  
    TEST_ASSERT_EQUAL_INT(expected,res);  
    TEST_ASSERT_EQUAL_INT(in_num, num);    // check num  
    if ( num != 0 ) 
    TEST_ASSERT_EQUAL_INT64_ARRAY(vec, vec1+1, num);    // check vec 
    
}


void test_NullVector()
{ 
    run_test((long[]){0},0,0); 
}
void test_One()
{ 
    run_test((long[]){21},1,1); 
}
void test_Zero()
{ 
    run_test((long[]){1,0,-1},3,0); 
}
void test_Three()
{ 
    run_test((long[]){1001,10000,0x1000000000001},3,3); 
}
void test_Five()
{ 
    run_test((long[]){10,10,10,10,10},5,0); 
}

int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_NullVector);
    RUN_TEST(test_One);
    RUN_TEST(test_Zero);
    RUN_TEST(test_Three);
    RUN_TEST(test_Five);
    return UNITY_END();  

  } 






