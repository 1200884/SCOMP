#include <string.h>  
#include "../../unity.h"
#include "asm.h" 



void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(short vecs_in[], int num  )
{
    short vec_in[100];
    int vec_out[100];


    // setup 
      
	memset(vec_in, 0x55, sizeof vec_in);
	memset(vec_out, 0x55, sizeof vec_out);
	memcpy(vec_in+1,vecs_in,num*sizeof(short)); 
    compress_shorts(vec_in+1,num,vec_out+1);  

    
    TEST_ASSERT_EQUAL_INT16_MESSAGE(0x5555, vec_in[0],"Sentinel 1");    // check sentinel 
    TEST_ASSERT_EQUAL_INT16_MESSAGE(0x5555, vec_in[num+1],"Sentinel 2");    // check sentinel 
    TEST_ASSERT_EQUAL_INT_MESSAGE(0x55555555, vec_out[0],"Sentinel 1");    // check sentinel 
    TEST_ASSERT_EQUAL_INT_MESSAGE(0x55555555, vec_out[num/2+1],"Sentinel 2");    // check sentinel 

    if (num>0)
    { 
        TEST_ASSERT_EQUAL_MEMORY(vecs_in,vec_out+1,num/2*sizeof(int));    // 
        
    } 
 
}


void test_NullVec()
{ 
    run_test((short[]){0},0); 
}
void test_One()
{ 
    run_test((short[]){1,2},2); 
}
void test_Three()
{ 
    run_test((short[]){1,2,3,4,5,6},6); 
}
void test_Four()
{ 
    run_test((short[]){1,2,3,4,5,6,7,8},8); 
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






