#include <stddef.h>
#include <stdio.h>

int alphabet(char c)
{
    while (c <= 'z')
    {
        if (c == 'z')
        {
            putchar(c);
            c++;
        }
        else
        {
            putchar(c);
            putchar(' ');
            c++;
        }
    }
    return 0;
}

int main(void)
{
    int i = alphabet('a');
    putchar('\n');
    return i;
}
