#include <stdio.h>
#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t count = 0;
    while(s[count] != '\0')
    {
        count++;
    }
    return count;
        
}

int main(void)
{
    const char s[] = "toto";
    size_t count = my_strlen(s);
    printf("%ld\n", count);
}
