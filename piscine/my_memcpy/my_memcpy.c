#include <stddef.h>
#include <stdio.h>

void *my_memcpy(void *dest, const void *source, size_t num)
{
    // diff with memmove, no overlapping of source and dest
    // How do we know if they overlapp ??
    char *d = dest;
    const char *s = source;

    while (num--) // new way of implementing (not with for loop)
    {
        *d++ = *s++;
    }
    return dest;
}
