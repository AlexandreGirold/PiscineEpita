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

/*static void reorganize(struct heap *heap, int index)
{
    int daddy = (index - 1) / 2;
    if (heap->array[daddy] < heap->array[index])
    {
        int temp = heap->array[daddy];
        heap->array[daddy] = heap->array[daddy];
        heap->array[index] = temp;

        reorganize(heap, daddy);
    }
}*/

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

void add(struct heap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        heap->capacity *= 2;
        heap->array = realloc(heap->array, sizeof(int) * heap->capacity);
    }
    if (heap->size < heap->capacity)
    {
        size_t s = heap->size;
        heap->array[s] = val;
        reorganize(heap, s);
        heap->size++; // ajouter 1;
    }
}
