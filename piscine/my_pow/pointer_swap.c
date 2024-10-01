#include <stdio.h>
#include <stddef.h>

void pointer_swap(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    int *px = &x, *py = &y;

    printf("Before swap: px = %p, py = %p\n", (void*)px, (void*)py);
    pointer_swap(&px, &py);
    printf("After swap: px = %p, py = %p\n", (void*)px, (void*)py);

    return 0;
}
