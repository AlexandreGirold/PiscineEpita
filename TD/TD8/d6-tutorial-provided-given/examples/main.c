#include <stdio.h> // needed for printf()

#include "test.h" // needed for test_func_2()

int main(void)
{
    int ret = test_func_2();

    printf("%d\n", ret);

    return 0;
}
