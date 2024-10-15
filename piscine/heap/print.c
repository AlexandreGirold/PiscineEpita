#include <stddef.h>
#include <stdio.h>

#include "heap.h"

static void print_h(const struct heap *h, size_t index)
{
    if (index >= h->size)
        return;
    printf(" %d", h->array[index]);
    print_h(h, 2 * index + 1);
    print_h(h, 2 * index + 2);
}

void print_heap(const struct heap *heap)
{
    if (heap->size == 0)
        return;
    printf("%d", heap->array[0]);
    print_h(heap, 1);
    print_h(heap, 2);
    printf("\n");
}
