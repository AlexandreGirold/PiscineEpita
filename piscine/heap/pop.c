#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void reorganize(struct heap *heap, size_t index)
{
    size_t largest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;
    
    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;
    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != index) {
        swap(&heap->array[index], &heap->array[largest]);
        reorganize(heap, largest);
    }
}
/*
static void reorganize(struct heap *heap, size_t index)
{
    while (index > 0)
    {
        size_t parent = (index - 1) / 2;
        if (heap->array[parent] >= heap->array[index])
            return;
        swap(&heap->array[parent], &heap->array[index]);
        index = parent;
    }
}
*/
int pop(struct heap *heap)
{
    if (heap->size == 0 || !heap)
        assert(heap->size > 0);
    int res = heap->array[0];
    heap->array[0] = heap->array[(heap->size) - 1];
    heap->array[(heap->size) - 1] = -1;
    heap->size--;
    reorganize(heap, 0);
    if (heap->size < heap->capacity / 2 && heap->capacity > 8)
    {
        heap->capacity /= 2;
        heap->array = realloc(heap->array, sizeof(int) * heap->capacity);
    }

    return res;
}
