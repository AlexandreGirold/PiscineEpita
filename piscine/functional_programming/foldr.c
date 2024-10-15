#include <stdio.h>

#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    // size_t i = 0;
    if (0 < len)
    {
        // len--;
        return func(array[0], foldr(array + 1, len - 1, func));
    }
    return 0;
}
