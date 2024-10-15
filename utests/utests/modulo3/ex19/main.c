#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


void call_func ( void (*f)(void) );  
char * ptrgrades ;   
int * ptrfreq;  
int num; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(char * grades, int in_num, int * exp_vec)
{
    char vec1[100];
    int vec2[23];
    int res; 

    // setup 
        memset(vec1, 0x55, sizeof vec1);
        memset(vec2, 0x55, sizeof vec2);
     
        ptrgrades=vec1+1; 	
        ptrfreq=vec2+1; 	

	memcpy(vec1+1,grades,in_num*sizeof(char));  //   
        num = in_num; 
	call_func(frequencies);
    
    TEST_ASSERT_EQUAL_INT8(0x55, vec1[in_num+1]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT8(0x55, vec1[0]);    // check sentinel  
    TEST_ASSERT_EQUAL_INT(in_num, num);    // check num  
    TEST_ASSERT_EQUAL_INT(0x55555555, vec2[22]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT(0x55555555, vec2[0]);    // check sentinel  

    TEST_ASSERT_EQUAL_INT_ARRAY(exp_vec, vec2+1, 21);    // check vec 
}


void test_NullVector()
{   
    run_test((char[]){0},0,	
        // 0 1 2 3 4 5  6 7 8 9 0   1 2 3 4 5  6 7 8 9 0			
   (int[]){0,0,0,0,0,0, 0,0,0,0,0,  0,0,0,0,0, 0,0,0,0,0});
}
void test_One()
{   
    run_test((char[]){1},1,	
        // 0 1 2 3 4 5  6 7 8 9 0   1 2 3 4 5  6 7 8 9 0			
   (int[]){0,1,0,0,0,0, 0,0,0,0,0,  0,0,0,0,0, 0,0,0,0,0});
}     
void test_Zero()
{   
    run_test((char[]){2,1,0},3,	
        // 0 1 2 3 4 5  6 7 8 9 0   1 2 3 4 5  6 7 8 9 0			
   (int[]){1,1,1,0,0,0, 0,0,0,0,0,  0,0,0,0,0, 0,0,0,0,0});
}     
void test_Three()
{   
    run_test((char[]){20,10,3},3,	
        // 0 1 2 3 4 5  6 7 8 9 0   1 2 3 4 5  6 7 8 9 0			
   (int[]){0,0,0,1,0,0, 0,0,0,0,1,  0,0,0,0,0, 0,0,0,0,1});
}     
void test_Five()
{   
    run_test((char[]){20,10,10,10,10,10},6,	
        // 0 1 2 3 4 5  6 7 8 9 0   1 2 3 4 5  6 7 8 9 0			
   (int[]){0,0,0,0,0,0, 0,0,0,0,5,  0,0,0,0,0, 0,0,0,0,1});
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






