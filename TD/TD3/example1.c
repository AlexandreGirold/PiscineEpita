#include <stdio.h>

int main(void)
{
        char c = 'A';
        c  += 'a' - 'A';

        if (c >= 'a' && c <= 'z')
                puts("'c' has become  a lowercase character!");

        return 0;
}

