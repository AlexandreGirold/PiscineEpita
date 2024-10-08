#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void *my_calloc(size_t n, size_t size)
{
    size_t len = n * size;
    size_t i = 0;
    char *s = malloc(len);
    if (!s)
        return NULL;
    while (i < len)
    {
        s[i] = 0;
        i++;
    }
    return s;
}
