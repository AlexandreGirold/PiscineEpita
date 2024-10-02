#include <stddef.h>
#include <stdio.h>

unsigned int greatest_divisor(unsigned int n)
{
    for (unsigned int i = n / 2; i > 0; i--)
    {
        if (n % i == 0)
        {
            return i;
        }
    }

    return 1;
}
