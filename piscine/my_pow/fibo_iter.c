#include <stdio.h>
#include <stddef.h>

unsigned long fibo_iter(unsigned long n){
    
    unsigned long n1 = 0;
    unsigned long n2 = 1;
    
    if (n == 0)
        return 0;

    for (int i = 1; i<n; i++)
    {
        unsigned long temp;
        temp = n2;
        n2 = n2 + n1;
        n1 = temp;
    }
    return n2;
}
