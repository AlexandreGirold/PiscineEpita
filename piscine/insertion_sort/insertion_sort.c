#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*f_cmp)(const void *, const void *);

void swap(void **a, void **b)
{
    // On maitrise la swap
    void *temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(void **array, f_cmp comp)
{
    if (!array)
        return;
    if (!comp)
        return;
    if (*array == NULL)
        return;
    for (size_t i = 1; array[i] != NULL; i++)
        for (size_t j = i; j > 0 && comp(array[j - 1], array[j]) > 0; j--)
            swap(&array[j - 1], &array[j]);
}
