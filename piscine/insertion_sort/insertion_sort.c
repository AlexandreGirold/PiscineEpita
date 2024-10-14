#include <stddef.h>
#include <stdlib.h>
#include "insertion_sort.h"

void insertion_sort(void **array, f_cmp comp) {
    if (array == NULL || comp == NULL) {
        return; // Invalid input
    }

    for (size_t i = 1; array[i] != NULL; i++) {
        void *key = array[i];
        size_t j = i - 1;

        // Move elements of array[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j != (size_t)(-1) && comp(array[j], key) > 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
