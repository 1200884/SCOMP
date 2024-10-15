#include <string.h>  
#include "../../unity.h"
#include "asm.h" 



void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(char * str1, char * str2 , int pos )   // pos = position in the string  ( 0... )
                                                     //     -1 = does not exist 
{
    
    char * res; 
    res=where_exists(str1,str2);  
    printf("res = %p \n",res); 
    if (pos==-1)
        TEST_ASSERT_NULL(res); 
       else 
        TEST_ASSERT_EQUAL_PTR(str2+pos,res); 
    
}


void test_Two()
{ 
    run_test("x","rrxXXXX",2); 
}

void test_Four()
{ 
    run_test("xrt","aarrxrt xrt xrt xrt",4); 
}


void test_Eight()
{ 
    run_test("xrt","xaixrarrxrt xrt xrt xrt",8); 
}

void test_Null1()
{ 
    run_test("","",-1);  
}

void test_Null2()
{ 
    run_test("","dfdfkgld kgad",-1);  
}

void test_Null3()
{ 
    run_test("hgasgd ","",-1);  
}

void test_Null4()
{ 
    run_test("zz","z",-1);  
}



int main()
  { 
    UNITY_BEGIN();
//    RUN_TEST(test_Two);
//.    RUN_TEST(test_Four);
//    RUN_TEST(test_Eight);
//    RUN_TEST(test_Null1);
//    RUN_TEST(test_Null2);
//    RUN_TEST(test_Null3);
    RUN_TEST(test_Null4);
    return UNITY_END();  
  } 






