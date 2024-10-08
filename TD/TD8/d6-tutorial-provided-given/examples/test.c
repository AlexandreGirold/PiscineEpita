#include "test.h" // needed for TEST_VAL_1 and TEST_VAL_2
static int test_func_1(void)
{
    return TEST_VAL_1;
}
int test_func_2(void)
{
    return test_func_1() + TEST_VAL_2;
}
