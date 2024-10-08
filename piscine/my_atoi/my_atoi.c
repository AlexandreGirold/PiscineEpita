#include <stddef.h>
#include <stdio.h>

int my_atoi(const char *str)
{
    int res = 0;
    int neg = 1; // false
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

    while (*str >= '0' && *str <= '9')
    {
        res = res * 10;
        res += *str - '0';
        str++;
    }
    if ((!(*str >= '0') || !(*str <= '9')) && *str != '\0')
        return 0;

    return neg * res;
}
