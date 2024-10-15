#include <stdio.h>

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    unsigned min_index = start;
    for (unsigned i = start + 1; i < size; ++i)
    {
        if (arr[i] < arr[min_index])
        {
            min_index = i;
        }
    }
    return min_index;
}

void selection_sort(int arr[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        unsigned min_index = array_min(arr, i, size);
        if (min_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}
/*
int main(void) {
    const unsigned size = 35;
    int arr[] = {
        5, 8, 90, 3, 7, 64, 10224, 88, 39, 78, 20, 6,
        9, 79, 30, 45, 908, 201, 73, 460, 1330, 37, 32, 13,
        709, 310, 1998, 2000, 2020, 2021, 2022, 5600, 10000, 4560, 4800,
    };
    unsigned expected[] = {
        3, 3, 3, 3, 11, 11, 11, 11, 11, 11, 11, 11, 12, 23, 23, 23, 23, 23,
        23, 23, 23, 23, 23, 23, 25, 25, 26, 27, 28, 29, 30, 33, 33, 33, 34,
    };

    for (unsigned i = 0; i < size; ++i)
        printf("%u: %u = %u\n", i, array_min(arr, i, size), expected[i]);

    printf("Before sorting:");
    for (unsigned i = 0; i < size; i++)
        printf(" %d", arr[i]);

    selection_sort(arr, size);

    printf("\nAfter sorting:");
    for (unsigned i = 0; i < size; i++)
        printf(" %d", arr[i]);

    return 0;
}*/
