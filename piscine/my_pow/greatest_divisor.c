#include <stdio.h>
#include <stddef.h>

unsigned int greatest_divisor(unsigned int n) {
    if (n <= 1) {
        return 0; // Since n is positive and non-zero, this case should not occur.
    }
    
    for (unsigned int i = n / 2; i > 0; i--) {
        if (n % i == 0) {
            return i;
        }
    }
    
    return 1; // If no divisor is found, return 1 (since 1 is a divisor of any number).
}
