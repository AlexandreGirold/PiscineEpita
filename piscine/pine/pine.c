#include <stddef.h>
#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
        return 1;
    unsigned trunk = n / 2;
    unsigned leaf = n * 2 - 1; // starting leaf
    unsigned white = n - 1;
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = i; j < white; j++)
        {
            putchar(' ');
        }

        for (unsigned j = leaf - i * 2; j <= leaf; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }

    for (unsigned i = 0; i < trunk; i++) // trunk
    {
        for (unsigned j = 0; j < white; j++)
        {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }
    return 0;
}

int main(void)
{
    return pine(8);
}
