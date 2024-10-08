#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    const char *p1 = s1;
    const char *p2 = s2;
    if (!p1 || !p2)
        return 0;

    for (size_t i = 0; i < num; i++)
    {
        if (p1[i] != p2[i])
            return p1[i] - p2[i];
    }
    return 0;
}
