#include <stddef.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int is_alpha_num(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return TRUE;

    if (ch >= '0' && ch <= '9')
        return TRUE;
    return FALSE;
}

int palindrome(const char *s)
{
    if (!s)
        return FALSE;
    int len = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        len++;
        i++;
    }
    i = 0;

    while (len >= i)
    {
        if (is_alpha_num(s[i]) && is_alpha_num(s[len]))
        {
            if (s[i] != s[len])
                return FALSE;
            i++;
            len--;
        }
        else
        {
            if (!is_alpha_num(s[i]))
                i++;
            if (!is_alpha_num(s[len]))
                len--;
        }
    }
    return TRUE;
}
