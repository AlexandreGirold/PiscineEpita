#include <stdlib.h>
#include "heap.h"
#include <assert.h>

static void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void heapify_up(struct heap *heap, size_t index) 
{
    while (index > 0) {
        size_t parent = (index - 1) / 2;
        if (heap->array[parent] >= heap->array[index]) break;
        swap(&heap->array[parent], &heap->array[index]);
        index = parent;
    }
}

void add(struct heap *heap, int val) 
{
    if (heap->size >= heap->capacity) 
    {
        heap->capacity *= 2;
        heap->array = realloc(heap->array, heap->capacity * sizeof(int));
    }
    heap->array[heap->size] = val;
    heapify_up(heap, heap->size);
    heap->size++;
}
