#include <stddef.h>
#include <stdio.h>

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    if (!max || !min || !tab || len == 0)
        return;
    *min = tab[0];
    *max = tab[0];
    for (size_t i = 0; i < len; i++)
    {
        if (tab[i] < *min)
            *min = tab[i];
        else if (tab[i] > *max)
            *max = tab[i];
    }
}
