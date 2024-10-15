#include <stdio.h>

#include "functional_programming.h"

int foldl(int *array, size_t len, int (*func)(int, int))
{
    if (0 < len)
    {
        len--;
        return func(foldl(array, len, func), array[len]);
    }
    return 0;
}
