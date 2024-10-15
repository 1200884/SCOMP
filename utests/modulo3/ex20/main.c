#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(void) );  
int * ptrvec;  
int num; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int * vec, int in_num, int  expected )
{
    int vec1[100];

    int res;

    // setup 
        memset(vec1, 0x55, sizeof vec1);
     
        ptrvec=vec1+1; 	
	memcpy(vec1+1,vec,in_num*sizeof(int));  //   
        num = in_num; 
	res=call_func(count_seq);
    
    TEST_ASSERT_EQUAL_INT(0x55555555, vec1[in_num+1]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT(0x55555555, vec1[0]);    // check sentinel  
    TEST_ASSERT_EQUAL_INT(expected,res);  
    TEST_ASSERT_EQUAL_INT(in_num, num);    // check num  
    if ( num != 0 ) 
    TEST_ASSERT_EQUAL_INT_ARRAY(vec, vec1+1, num);    // check vec 
    
}


void test_NullVector()
{ 
    run_test((int[]){0},0,0); 
}
void test_One()
{ 
    run_test((int[]){2},1,0); 
}
void test_Zero()
{ 
    run_test((int[]){-1,0,1},3,1); 
}
void test_Three()
{ 
    run_test((int[]){3,3,3},3,0); 
}
void test_Five()
{ 
    run_test((int[]){1,2,3,4,5},5,3); 
}
void test_Five2()
{ 
    run_test((int[]){10,20,30,40,50},5,3); 
}

int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_NullVector);
    RUN_TEST(test_One);
    RUN_TEST(test_Zero);
    RUN_TEST(test_Three);
    RUN_TEST(test_Five);
    RUN_TEST(test_Five2);
    return UNITY_END();  

  } 






