#include <stddef.h>
#include <stdio.h>

char *my_strcpy(char *dest, const char *source)
{
    // if not working add test on string her
    if (!dest || !source)
        return dest;
    size_t i = 0;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
