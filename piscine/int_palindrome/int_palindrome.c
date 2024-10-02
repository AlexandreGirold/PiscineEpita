#include <stddef.h>
#include <stdio.h>

int reverseNum(int N)
{
    int rev = 0;
    while (N > 0)
    {
        int dig = N % 10;
        rev = rev * 10 + dig;
        N /= 10;
    }
    return rev;
}

int int_palindrome(int n)
{
    if (n < 0)
        return 0;
    if (n == reverseNum(n))
        return 1;
    return 0;
}
