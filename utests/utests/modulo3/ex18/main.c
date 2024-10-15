#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(void) );  
int * ptrsrc;  
int * ptrdest;  
int num; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int * vec, int in_num, int expected, int * exp_vec)
{
    int vec1[100];
    int vec2[100];
    int res; 

    // setup 
        memset(vec1, 0x55, sizeof vec1);
        memset(vec2, 0x55, sizeof vec2);
     
        ptrsrc=vec1+1; 	
        ptrdest=vec2+1; 	

	memcpy(vec1+1,vec,in_num*sizeof(int));  //   
        num = in_num; 
	res=call_func(sort_without_reps);
    
    TEST_ASSERT_EQUAL_INT(0x55555555, vec1[in_num+1]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT(0x55555555, vec1[0]);    // check sentinel  
    TEST_ASSERT_EQUAL_INT(in_num, num);    // check num  
    TEST_ASSERT_EQUAL_INT(expected,res);   // check res  
    TEST_ASSERT_EQUAL_INT(0x55555555, vec2[res+1]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT(0x55555555, vec2[0]);    // check sentinel  

    if ( num != 0 ) 
    { 	    
	    TEST_ASSERT_EQUAL_INT_ARRAY(exp_vec, vec2+1, res);    // check vec 
    }  
}


void test_NullVector()
{ 
    run_test((int[]){0},0,0,(int[]){0}); 
}
void test_One()
{ 
    run_test((int[]){1000},1,1,(int[]){1000}); 
}
void test_Zero()
{ 
    run_test((int[]){10,0,1},3,3,(int[]){0,1,10}); 
}
void test_Three()
{ 
    run_test((int[]){-1,-3,-3},3,2,(int[]){-3,-1}); 
}
void test_Five()
{ 
    run_test((int[]){1,1,1,1,2},5,2,(int[]){1,2}); 
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






