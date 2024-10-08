#include <stddef.h>
#include <stdio.h>

int check_alphabet(const char *str, const char *alphabet)
{
    if (!alphabet)
        return 1;

    for (int i = 0; alphabet[i] != '\0'; i++)
    {
        int found = 0;
        for (int j = 0; str[j] != '\0'; j++)
        {
            if (str[j] == alphabet[i])
                found++;
        }
        if (found == 0)
            return 0;
    }
    return 1;
}
