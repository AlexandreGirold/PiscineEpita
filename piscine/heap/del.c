#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void delete_heap(struct heap *heap)
{
    free(heap->array);
    free(heap);
}
