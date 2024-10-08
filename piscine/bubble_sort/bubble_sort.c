#include <stddef.h>
#include <stdio.h>

void bubble_sort(int array[], size_t size)
{
    if (size == 0)
        return;
    for (size_t i = 0; i < size - 1;
         i++) // overfolow if size = 0 (because not int);
    {
        for (size_t j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1]; // ici on swappppppp
                array[j + 1] = temp; // ici aussi (enfin on copie)
            }
        }
    }
}
