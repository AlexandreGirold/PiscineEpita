#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
// Parent(i)=(i-1)/2
// left child(i)=2*i+1
// right child(i)=2*i+2
//
// NULL  will not be tested

struct heap *create_heap(void)
{
    struct heap *h = malloc(sizeof(struct heap));

    if (!h)
        return NULL; // error in allocating memory

    h->size = 0;
    h->capacity = 8;
    h->array = malloc(sizeof(int) * h->capacity);
    return h;
}
