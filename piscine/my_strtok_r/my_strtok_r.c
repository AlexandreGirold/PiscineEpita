#include <stddef.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

static int is_delim(const char *s, char c)
{
    const char *p = s;
    while (*p != '\0')
    {
        if (*p == c)
        {
            return TRUE;
        }
        p++;
    }
    return FALSE;
}

/*static int len(char *s)
{
    int len = 0;
    while(s[len] != '\0')
    {
        len++;
    }
    return len;
}*/

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if (str == NULL)
        str = *saveptr;

    // int i = 0
    if (str == NULL && *saveptr == NULL)
        return NULL;
    while (*str != '\0' && is_delim(delim, *str))
        str++;

    if (*str == '\0')
    {
        *saveptr = NULL;
        return NULL;
    }

    char *tok = str;
    while (!is_delim(delim, *str) && *str)
    {
        str++;
    }
    if (*str)
    {
        *str = '\0';
        *saveptr = str + 1;
    }
    else
    {
        *saveptr = NULL;
    }

    return tok;
}
/*
int main(void)
{
    char str[]= "192.0.0.1";
    char *delim = ".";
    char *saveptr;

    char *tok = my_strtok_r(str, delim, &saveptr);
    while(tok != NULL)
    {
        printf("%s\n",tok);
        tok = my_strtok_r(NULL, delim, &saveptr);
    }
    return 0;
}*/
