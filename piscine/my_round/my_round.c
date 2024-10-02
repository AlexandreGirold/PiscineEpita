#include <stddef.h>
#include <stdio.h>

int my_round(float n)
{
    if (n < 0.0)
        return (n - 0.5) / 1;
    else
        return (n + 0.5) / 1;
}
