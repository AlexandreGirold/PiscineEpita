#include <stddef.h>
#include <stdio.h>

void plus_equal(int *a, int *b)
{
    if (!a || !b)
        return;
    int temp = *a + *b;
    *a = temp;
    return;
}

void minus_equal(int *a, int *b)
{
    if (!a || !b)
        return;
    int temp = *a - *b;
    *a = temp;
    return;
}

void mult_equal(int *a, int *b)
{
    if (!a || !b)
        return;
    int temp = *a * *b;
    *a = temp;
    return;
}

int div_equal(int *a, int *b)
{
    if (b == NULL || a == NULL)
        return 0;
    if (*b == 0)
        return 0;
    int temp = *a;
    *a = *a / *b;
    return temp % *b;
}
