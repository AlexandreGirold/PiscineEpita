#include <stdio.h>

#include "palindrome/palindrome.h"

int main(void)
{
    const char str[] = "S11S1_@?S";
    int a = palindrome(str);
    printf("%d\n", a);
    return 0;
}
