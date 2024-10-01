#include <stdio.h>
#include <stddef.h>

unsigned int digit(int n, int k) {
    if (n <= 0 || k <= 0) {
        return 0;
    }
    
    for (int i = 1; i < k; i++) {
        n /= 10;
    }
    
    return n % 10;
}

int main() {
    printf("digit(123456, 2) = %u\n", digit(123456, 2)); // Output: 5
    printf("digit(123456, 4) = %u\n", digit(123456, 4)); // Output: 3
    printf("digit(123456, 7) = %u\n", digit(123456, 7)); // Output: 0
    printf("digit(-123456, 4) = %u\n", digit(-123456, 4)); // Output: 0
    printf("digit(123456, -4) = %u\n", digit(123456, -4)); // Output: 0

    return 0;
}
