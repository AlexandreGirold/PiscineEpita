#include <stdlib.h>

int main(void)
{
    int *p;
    int i;

    p = malloc(5 * sizeof(int));
    for (i = 0; i < 5; i++)
        p[i] = i;

    return 0;
}
