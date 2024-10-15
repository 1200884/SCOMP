#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


void call_func ( void (*f)(void) );  
long * ptrvec;  
int num; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(long * vec, int in_num, long * expected )
{
    long vec1[100];

    

    // setup 
        memset(vec1, 0x55, sizeof vec1);
     
        ptrvec=vec1+1; 	
	memcpy(vec1+1,vec,in_num*sizeof(long));  //   
        num = in_num; 
	call_func(vec_add_one);
    
    TEST_ASSERT_EQUAL_INT64(0x5555555555555555, vec1[in_num+1]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT64(0x5555555555555555, vec1[0]);    // check sentinel  
    if (num !=0) 
	    TEST_ASSERT_EQUAL_INT64_ARRAY(expected, vec1+1, in_num);  
    TEST_ASSERT_EQUAL_INT(in_num, num);    // check num 
    TEST_ASSERT_EQUAL_PTR(vec1+1, ptrvec);    // check ptrvec 
    
}


void test_NullVector()
{ 
    run_test((long[]){0},0,(long[]){0}); 
}
void test_One()
{ 
    run_test((long[]){1},1,(long[]){2}); 
}
void test_Zero()
{ 
    run_test((long[]){1,0,-1},3,(long[]){2,1,0}); 
}
void test_Minus()
{ 
    run_test((long[]){-2,-2,-2},3,(long[]){-1,-1,-1}); 
}
void test_Five()
{ 
    run_test((long[]){1,2,3,4,255},5,(long[]){2,3,4,5,256}); 
}

int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_NullVector);
    RUN_TEST(test_One);
    RUN_TEST(test_Zero);
    RUN_TEST(test_Minus);
    RUN_TEST(test_Five);
    return UNITY_END();  

  } 






