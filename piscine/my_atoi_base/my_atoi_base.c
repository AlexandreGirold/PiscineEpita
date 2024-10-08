#include <stddef.h>
#include <stdio.h>

int len(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

int my_atoi_base(const char *str, const char *base)
{
    if (!str || !base || len(base) < 2)
        return 0;

    int res = 0;
    int neg = 1; // false
    int len_b = len(base);
    int has_c = 0;
    while (*str == ' ')
    {
        ++str;
    }
    if (*str == '+')
    {
        neg = 1;
        ++str;
    }
    else if (*str == '-')
    {
        neg = -1;
        ++str;
    }
    while (*str)
    {
        int index = 0;
        while (index < len_b && base[index] != *str)
        {
            index++;
        }
        if (index == len_b)
            return 0;
        has_c = 1;
        res = res * len_b + index;
        ++str;
    }
    if (!has_c)
        return 0;
    return neg * res;
}
