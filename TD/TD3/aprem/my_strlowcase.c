#include <stdio.h>
#include <stddef.h>


void my_strlowcase(char *str)
{
    int i=0;
    while(str[i] != '\0')
    {
        if (str[i] <= 'Z' && str[i] >= 'A')
        {
            str[i] += 32;
        }
        i++;
    }

}

int main(void)
{
    char str[] = "azerty1234XYZ &(";
    my_strlowcase(str);
    printf("%s", str);
}
