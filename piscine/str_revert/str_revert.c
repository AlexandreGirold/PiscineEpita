#include <stddef.h>
#include <stdio.h>

void str_revert(char str[])
{
    size_t len = 0;
    int j = 0;
    while (str[j] != '\0')
    {
        len++;
        j++;
    }
    for (size_t i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
