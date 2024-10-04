#include <stdlib.h>
#define SIZE 69000

void initialize(int *tab, int index, int value)
{
   tab[index] = value;
}

void guilty_function()
{
    int *tab;
    int i;
    tab = malloc(SIZE * sizeof(int));
    for (i = 0; i < 69000; ++i)
        initialize(tab, i, i);
    free(tab);
}

int main(void)
{
    guilty_function();
    return 0;
}
