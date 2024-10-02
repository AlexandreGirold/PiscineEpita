#include <stdio.h>
#include <stddef.h>

char *my_strcpy(char *dest, const char *source)
{
    //if not working add test on string here
    size_t i = 0;
    while (dest[i] != '\0' || source[i] != '\0')
    {
        dest[i] = source[i];
        i++
    }
    return dest;
}


