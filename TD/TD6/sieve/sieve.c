#include <stdio.h>

void sieve(int n)
{
    if(n < 2)
        return;
    char prime[1000] = {0};
    // 0 not encountered, 1 prime, 2 multiple of a number
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            prime[i] = 1;
            printf("%d\n", i);
            for (int j = i; j <= n; j = j + i)
            {
                prime[j] = 2;
            }
        }
    }
}


int main(void)
{
    int n = 31;
    sieve(n);
    return 0;
}
