#include <stddef.h>
#include <stdio.h>

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned int position = 1;

    for (unsigned char i = 1; i < n; ++i)
    {
        position *=
            2; // revient a multiplier un binaire 1(1) -> 10(2) -> 100(4) ect...
    }

    return (value / position) % 2;
}
