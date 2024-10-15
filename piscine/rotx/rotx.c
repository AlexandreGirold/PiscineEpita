#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char cypher(char s, int x)
{
    if (s >= '0' && s <= '9')
    {
        x = x % 10;
        if ((s + x) > '9')
            s = s + x - 10;
        else if ((s + x) < '0')
            s = s + x + 10;
        else
            s = s + x;
    }
    else if (s >= 'a' && s <= 'z')
    {
        x = x % 26;
        if (s + x > 'z')
            s = s + x - 26;
        else if (s + x < 'a')
            s = s + x + 26;
        else
            s = s + x;
    }
    else if (s >= 'A' && s <= 'Z')
    {
        x = x % 26;
        if (s + x > 'Z')
            s = s + x - 26;
        else if (s + x < 'A')
            s = s + x + 26;
        else
            s = s + x;
    }
    return s;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        return 0;

    if (argc != 2)
        return 0;
    char ch;
    int x = atoi(argv[1]);
    while (read(STDIN_FILENO, &ch, 1) > 0)
    {
        ch = cypher(ch, x);
        write(STDOUT_FILENO, &ch, 1);
    }

    return 0;
}
