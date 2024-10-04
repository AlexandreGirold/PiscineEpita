#include <stdlib.h>

int main(void)
{
    int *p;
    int a;

    p = malloc(10 * sizeof(int));

    p[11] = 1;
    a = p[11];

    free(p);

    return 0;
}
