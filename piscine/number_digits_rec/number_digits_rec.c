#include <stdio.h>

unsigned int number_digits_rec(unsigned int n)
{
    if (n / 10 == 0)
        return 1;

    n = n / 10;
    return 1 + number_digits_rec(n);
}
