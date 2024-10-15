#include <stddef.h>
#include <stdio.h>

static void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void quicksort(int *tab, size_t len)
{
    if (tab == NULL || len <= 1)
    {
        return;
    }

    int pivot = tab[len - 1];
    size_t i = 0;
    size_t j = 0;

    while (j < len - 1)
    {
        if (tab[j] <= pivot)
        {
            swap(&tab[i], &tab[j]);
            i++;
        }
        j++;
    }
    swap(&tab[i], &tab[len - 1]);

    quicksort(tab, i);
    quicksort(tab + i + 1, len - i - 1);
}
