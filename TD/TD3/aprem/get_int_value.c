#include <stdio.h>


int get_int_value(int *n)
{
    return *n;
}

int main(void)
{
    int a = 12;
    printf("%d\n", get_int_value(&a));
}

