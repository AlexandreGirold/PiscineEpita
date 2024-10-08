#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;
    if (d < s)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (d && s)
                d[i] = s[i];
        }
    }
    else
    {
        for (size_t i = n; i > 0; i--)
        {
            if (d && s)
                d[i - 1] = s[i - 1];
        }
    }
    return dest;
}
