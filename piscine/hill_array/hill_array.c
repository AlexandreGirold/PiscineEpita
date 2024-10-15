#include "hill_array.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int hill_max(int tab[], size_t len)
{
    int i = 0;
    for (size_t j = 0; j < len; j++)
    {
        if (tab[j] > tab[i])
            i = j;
    }
    return i;
}

int top_of_the_hill(int tab[], size_t len)
{
    size_t size = len;
    size_t i = 0;
    size_t x = 0;

    if (len > 0)
    {
        while (tab[i] <= tab[i + 1])
        {
            if (tab[i] < 0)
                return -1;
            if (i + 1 == size)
                x = len;
            else
                x = i + 1;
            i++;
        }
        for (size_t j = x; j < len - 1; j++)
        {
            if (tab[j] < 0)
                return -1;
            if (tab[j] < tab[j + 1])
                return -1;
        }
    }
    x = hill_max(tab, len);
    return x;
}

/*int main(void)
{
    int tab1[] = { 1, 2, 3, 4, 6, 6, 4, 2, 0, 0 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab1, 10)); // Expected: 4

    int tab2[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6, 6 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab2, 10)); // Expected: 5

    int tab3[] = { 1, 2, 3, 4, 6, 6, 4, 5, 0, 0 }; // Invalid hill.
    printf("%d\n", top_of_the_hill(tab3, 10)); // Expected: -1

    int tab4[] = { 1, 2, 3, 4, 3, 2, 1, 0, -1, -4 }; // Invalid hill.
    printf("%d\n", top_of_the_hill(tab4, 10)); // Expected: -1

    return 0;
}*/
