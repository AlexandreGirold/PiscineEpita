#include <stdio.h>
static void towerOfHanoi(int n, char start, char mid, char end);

void hanoi(unsigned n)
{
    char start = '1';
    char mid = '2';
    char end = '3';
    towerOfHanoi(n, start, end, mid);
}

static void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("%c->%c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("%c->%c\n", from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
