#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


void call_func ( void (*f)(void) );  
int * ptrvec;  
unsigned short num; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int * vec, unsigned short in_num, int * exp_vec)
{
    int vec1[100];


    // setup 
        memset(vec1, 0x55, sizeof vec1);
     
        ptrvec=vec1+1; 	
	memcpy(vec1+1,vec,in_num*sizeof(int));  //   
        num = in_num; 
	call_func(keep_positives);
    
    TEST_ASSERT_EQUAL_INT(0x55555555, vec1[in_num+1]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT(0x55555555, vec1[0]);    // check sentinel  
    TEST_ASSERT_EQUAL_UINT16(in_num, num);    // check num  
    if ( num != 0 ) 
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_vec, vec1+1, num);    // check vec 
    
}


void test_NullVector()
{ 
    run_test((int[]){0},0,(int[]){0}); 
}
void test_One()
{ 
    run_test((int[]){0},1,(int[]){0}); 
}
void test_Zero()
{ 
    run_test((int[]){-1,0,1},3,(int[]){0,0,1}); 
}
void test_Three()
{ 
    run_test((int[]){-1,-1,-1},3,(int[]){0,1,2}); 
}
void test_Five()
{ 
    run_test((int[]){1000,10000,20000,-1000,-5000},5,(int[]){1000,10000,20000,3,4}); 
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






