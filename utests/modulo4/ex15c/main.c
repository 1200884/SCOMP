#include <string.h>  
#include "../../unity.h"
#include "asm.h" 


int call_func ( int (*f)(int x, int y, int z), int x, int y , int z  );  

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int y, int z, int expected )
{
    int  res; 

    

    // setup 
	res = call_func(activate_invert_bits,x,y,z);
    
    TEST_ASSERT_EQUAL_INT(expected,res); 
    
}


void test_Zero()
{ 
    run_test(0,31,0,~0); 
}
void test_One()
{ 
    run_test(0,24,7,~0xfe00007f); 
}
void test_Two()
{ 
    run_test(0,30,1,~0x80000001); 
}
void test_Three()
{ 
    run_test(0,29,2,~0xc0000003); 
}
void test_Four()
{ 
    run_test(0,7,24,~0xffffffff); 
}

void test_Five()
{ 
    run_test(-1,31,0,~0xffffffff); 
}

void test_Six()
{ 
    run_test(-1,7,24,~0xffffffff); 
}

void test_Seven()
{ 
    run_test(0x55555555,24,7,~0xff55557f); 
}

void test_Eight()
{ 
    run_test(0x55555555,29,2,~0xd5555557); 
}



int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_One);
    RUN_TEST(test_Two);
    RUN_TEST(test_Three);
    RUN_TEST(test_Four);
    RUN_TEST(test_Five);
    RUN_TEST(test_Six);
    RUN_TEST(test_Seven);
    RUN_TEST(test_Eight);
    return UNITY_END();  

  } 






