#include <stddef.h>
#include <stdio.h>

size_t my_strlen(const char *s)
{
    size_t count = 0;
    while (s[count] != '\0')
    {
        count++;
    }
    return count;
}
