#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


short * call_func ( short * (*f)(void) );  
short * ptrvec;  
int num; 
short x; 

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(short * vec, int in_num, short to_search, int expected_pos )
{
    short vec1[100];

    short *  res; 
    short * expected_ptr; 
    if (expected_pos == -1 ) 
	    expected_ptr=NULL; 
    else 
    	    expected_ptr = vec1+1+expected_pos; 

    // setup 
        memset(vec1, 0x55, sizeof vec1);
     
        ptrvec=vec1+1; 	
	memcpy(vec1+1,vec,in_num*sizeof(short));  //   
        num = in_num; 
	x = to_search; 
	res = call_func(vec_search);
    
    TEST_ASSERT_EQUAL_INT16(0x5555, vec1[in_num+1]);    // check sentinel 
    TEST_ASSERT_EQUAL_INT16(0x5555, vec1[0]);    // check sentinel  
    TEST_ASSERT_EQUAL_PTR(expected_ptr,res);  
    TEST_ASSERT_EQUAL_INT(in_num, num);    // check num 
    TEST_ASSERT_EQUAL_PTR(vec1+1, ptrvec);    // check ptrvec  
    if ( num !=0 ) 
	    TEST_ASSERT_EQUAL_INT16_ARRAY(vec,vec1+1,in_num); // check if vector has changed 
    
}


void test_NullVector()
{ 
    run_test((short[]){0},0,0,-1); 
}
void test_One()
{ 
    run_test((short[]){1},1,1,0); 
}
void test_Zero()
{ 
    run_test((short[]){1,0,-1},3,0,1); 
}
void test_Minus3()
{ 
    run_test((short[]){-1,-1,-1,-3},4,-3,3); 
}
void test_Five()
{ 
    run_test((short[]){-1,-1,-1,-3,1},5,1,4); 
}
void test_NotFound()
{ 
    run_test((short[]){-1,-1,-1,-3,1},5,0,-1); 
}

int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_NullVector);
    RUN_TEST(test_One);
    RUN_TEST(test_Zero);
    RUN_TEST(test_Minus3);
    RUN_TEST(test_Five);
    RUN_TEST(test_NotFound);
    return UNITY_END();  

  } 






