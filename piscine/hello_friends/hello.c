#include <stddef.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    size_t size = argc;
    if (size < 2)
        printf("Hello World!\n");
    else
    {
        for (size_t i = 1; i < size; i++)
        {
            printf("Hello %s!\n", argv[i]);
        }
    }
}
