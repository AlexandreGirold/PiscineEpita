#include <stddef.h>
#include <stdio.h>

unsigned int digit(int n, int k)
{
    if (n <= 0 || k <= 0)
    {
        return 0;
    }

    for (int i = 1; i < k; i++)
    {
        n /= 10;
    }

    return n % 10;
}
