#include <stdio.h>
#include <stdlib.h>

void *my_calloc(size_t n, size_t size)
{
    size_t *arr = malloc(size);
    if (!arr)
        return;
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
}

void my_free(void *prt)
{
    
    if (iprt != NULL)
        realloc(ptr,0);
}

void *my_malloc (size_t size)
{
    if(!prt)
    {
        realloc(0, size);
    }
}
