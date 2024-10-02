#include <stddef.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
        return 1;
    for (int i = 6; i < argv[2][0] - 42; i++)
    {
        puts(argv[1]);
    }
    return 0;
}
