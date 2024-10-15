#include <string.h>  
#include "../../unity.h"
#include "asm.h" 



void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int vec1_in[], int  vec2_in[] , int num  )
{
    int vec1[100];
    int vec2[100];


    // setup 
      
	memset(vec1, 0x55, sizeof vec1);
	memset(vec2, 0x55, sizeof vec2);
	memcpy(vec1+1,vec1_in,num*sizeof(int)); 
    memcpy(vec2+1,vec2_in,num*sizeof(int)); 
	swap(vec1+1,vec2+1,num); 
    
    TEST_ASSERT_EQUAL_INT_MESSAGE(0x55555555, vec1[0],"Sentinel 1");    // check sentinel 
    TEST_ASSERT_EQUAL_INT_MESSAGE(0x55555555, vec1[num+1],"Sentinel 2");    // check sentinel 
    TEST_ASSERT_EQUAL_INT_MESSAGE(0x55555555, vec2[0],"Sentinel 1");    // check sentinel 
    TEST_ASSERT_EQUAL_INT_MESSAGE(0x55555555, vec2[num+1],"Sentinel 2");    // check sentinel 

    if (num>0)
    { 
        TEST_ASSERT_EQUAL_INT_ARRAY(vec2_in,vec1+1,num);    // 
        TEST_ASSERT_EQUAL_INT_ARRAY(vec1_in,vec2+1,num);    // 
    } 
 
}


void test_NullVec()
{ 
    run_test((int[]){0},(int[]){0},0); 
}
void test_One()
{ 
    run_test((int[]){1},(int[]){2},1); 
}
void test_Three()
{ 
    run_test((int[]){1,2,3},(int[]){3,2,1},3); 
}
void test_Four()
{ 
    run_test((int[]){1,2,3,4},(int[]){4,3,2,1},4); 
}




int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_NullVec);
    RUN_TEST(test_One);
    RUN_TEST(test_Three);
    RUN_TEST(test_Four);
    return UNITY_END();  

  } 






