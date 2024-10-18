//#include "bsearch.h"
#include <stddef.h>
#include <assert.h>
#include <stdio.h>

int *binary_search(int *begin, int *end, int elt) {
    while (begin < end) {
        int *mid = begin + (end - begin) / 2;

        if (*mid == elt) {
            return mid;
        } else if (*mid < elt) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }
    return begin;
}

int main(void) {
    int a[] = { 0, 1, 4, 5, 9, 10, 18, 22, 42, 51, 69 };
    
    assert(binary_search(a, a + 11, 5) == a + 3);
    assert(binary_search(a, a + 11, 0) == a);
    assert(binary_search(a, a + 11, -1) == a);
    assert(binary_search(a, a + 11, 99) == a + 11);
    assert(binary_search(a, a + 11, 68) == a + 10);

    printf("All tests passed successfully.\n");
    return 0;
}
