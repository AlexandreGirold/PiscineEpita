#include <stdio.h>
#include <string.h>
void reverse(char *input,  short index)
{
    if (index >= 0)
    {
        putchar(input[index]);
        reverse(input, --index);
    }
    else
         putchar('\n');
}


int main(void)
{
    char str[] = "orea.gnieob@s_ottacs";
    size_t len = strlen(str);
    reverse(str, len);
    return 0;
}
