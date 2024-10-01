#include <stdio.h>
#include <stddef.h>

int my_pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result *= a;
        }
        a *= a;
        b /= 2;
    }
    return result;
}

int main() {
    int base = 2;
    int exponent = 10;
    printf("%d^%d = %d\n", base, exponent, my_pow(base, exponent));
    return 0;
}
