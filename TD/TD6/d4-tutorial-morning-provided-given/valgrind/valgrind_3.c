#include <stdlib.h>

int main(void)
{
    int *p;
    int i;

    p = malloc(10 * sizeof(int));

    for (i = 0; i < 10; i++)
        p[i] = i;

    free(p);
    free(p);

    return 0;
}
