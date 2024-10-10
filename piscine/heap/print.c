#include <stdio.h>
#include "heap.h"

static void print_pre_order(const struct heap *heap, size_t index) {
    if (index >= heap->size) return;
    printf("%d ", heap->array[index]);
    print_pre_order(heap, 2 * index + 1);
    print_pre_order(heap, 2 * index + 2);
}

void print_heap(const struct heap *heap) {
    print_pre_order(heap, 0);
    putchar('\n');
}
