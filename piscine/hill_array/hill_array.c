#include "hill_array.h"
#include <stdio.h>
#include <errno.h>
#include <assert.h>

int top_of_the_hill(int tab[], size_t len) {
    if (len == 0) {
        return -1;  // Empty array is invalid
    }

    size_t i = 0;

    // Ascend the hill
    while (i < len - 1 && tab[i] < tab[i + 1]) {
        if (tab[i + 1] <= 0) {
            return -1; // Invalid if next number is non-positive
        }
        i++;
    }

    // Check if we reached the top
    if (i == 0 || i == len - 1) {
        return -1; // No peak found, or peak is at the edges
    }

    // Peak could have multiple equal elements
    size_t peak_start = i;
    while (i < len - 1 && tab[i] == tab[i + 1]) {
        i++;
    }

    // Descend the hill
    while (i < len - 1 && tab[i] > tab[i + 1]) {
        if (tab[i + 1] < 0) {
            return -1; // Invalid if next number is negative
        }
        i++;
    }

    // We must have reached the end
    if (i != len - 1) {
        return -1; // If we didn't reach the end, it's invalid
    }

    return peak_start; // Return the index of the top of the hill
}

int main(void) {
    int tab1[] = { 1, 2, 3, 4, 6, 6, 4, 2, 0, 0 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab1, 10)); // Expected: 4

    int tab2[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6, 6 }; // Valid hill.
    printf("%d\n", top_of_the_hill(tab2, 10)); // Expected: 5

    int tab3[] = { 1, 2, 3, 4, 6, 6, 4, 5, 0, 0 }; // Invalid hill.
    printf("%d\n", top_of_the_hill(tab3, 10)); // Expected: -1

    return 0;
}
