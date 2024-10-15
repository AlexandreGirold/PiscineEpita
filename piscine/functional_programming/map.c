#include <stddef.h>
#include <stdio.h>

void map(int *array, size_t len, void (*func)(int *))
{
    size_t i = 0;
    while (i < len)
    {
        func(&array[i]);
        i++;
    }
}

void times_two(int *a)
{
    *a *= 2;
}
