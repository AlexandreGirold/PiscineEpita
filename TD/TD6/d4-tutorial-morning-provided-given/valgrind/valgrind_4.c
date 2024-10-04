#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int *p;

    p = malloc(10);

    read(STDIN_FILENO, p, 100);
    free(p);

    return 0;
}
