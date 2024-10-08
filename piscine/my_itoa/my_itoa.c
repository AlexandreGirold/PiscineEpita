#include <stddef.h>
#include <stdio.h>

void reverse(char *s, int len)
{
    if (!s)
        return;
    int i = 0;
    if (s[0] == '-')
        i++;
    while (i < len)
    {
        char temp = s[i];
        s[i] = s[len];
        s[len] = temp;
        i++;
        len--;
    }
}

char *my_itoa(int value, char *s)
{
    int isneg = (value < 0) ? 1 : 0; // is not neg
    int i = 0;
    if (isneg)
    {
        value = -value; // abs
        s[i++] = '-';
    }

    if (value == 0)
    {
        s[i] = '0';
        i++;
        s[i] = '\0';
        return s;
    }
    while (value > 0)
    {
        int rest = value % 10;
        s[i++] = '0' + rest;
        value = value / 10;
    }

    reverse(s, i - 1);

    s[i] = '\0';

    return s;
}
