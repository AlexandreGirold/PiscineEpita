#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void *my_memset(void *s, int c, size_t n)
{
    if (!s)
        return s;
    char *ptr = s;
    for (size_t i = 0; i < n; i++)
    {
        ptr[i] = c;
    }
    return s;
}
