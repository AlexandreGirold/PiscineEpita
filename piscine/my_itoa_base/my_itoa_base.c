#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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

int len(const char *base)
{
    int len = 0;
    while (base[len] != '\0')
    {
        len++;
    }
    return len;
}

char *my_itoa_base(int n, char *s, const char *base)
{
    int isneg = (n < 0) ? 1 : 0; // is not neg
    int i = 0;
    if (isneg)
    {
        n = -n; // abs
        s[i++] = '-';
    }
    if (n == 0)
    {
        s[i] = base[i];
        i++;
        s[i] = '\0';
        return s;
    }
    while (n > 0 && isneg)
    {
        int rest = n % 10;
        s[i++] = '0' + rest;
        n = n / 10;
    }
    int l = len(base); // here ? Not null terminated??

    while (n > 0 && !isneg)
    {
        int rest = n % l;
        s[i++] = base[rest];
        n = n / l;
    }

    reverse(s, i - 1);

    s[i] = '\0';

    return s;
}
