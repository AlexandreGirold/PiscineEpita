#include <stddef.h>
#include <stdio.h>

int my_pow(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result *= a;
        }
        a *= a;
        b /= 2;
    }
    return result;
}
