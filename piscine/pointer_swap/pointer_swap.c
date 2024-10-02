#include <stddef.h>
#include <stdio.h>

void pointer_swap(int **a, int **b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}
