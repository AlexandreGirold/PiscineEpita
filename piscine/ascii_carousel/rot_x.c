#include <stddef.h>
#include <stdio.h>

void rot_x(char *s, int x)
{
    if (!s)
        return;
    x = x % 26; // from A to Z
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (s[i] + x > 'z')
                s[i] = s[i] + x - 26;
            else if (s[i] + x < 'a')
                s[i] = s[i] + x + 26;
            else
                s[i] = s[i] + x;
        }
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (s[i] + x > 'Z')
                s[i] = s[i] + x - 26;
            else if (s[i] + x < 'A')
                s[i] = s[i] + x + 26;
            else
                s[i] = s[i] + x;
        }
        i++;
    }
}
