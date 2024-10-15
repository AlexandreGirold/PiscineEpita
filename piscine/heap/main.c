#include <stdio.h>

#include "heap.h"

int main(void)
{
    struct heap *heap = create_heap();
    add(heap, 8);
    add(heap, 6);
    add(heap, 1);
    add(heap, 3);
    add(heap, 4);

    pop(heap);

    delete_heap(heap);
    return 0;
}
