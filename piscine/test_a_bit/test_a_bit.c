#include <stddef.h> 
#include <assert.h> 
#include <stdio.h>

unsigned int is_set(unsigned int value, unsigned char n) 
{
    unsigned int position = 1;

    
    for (unsigned char i = 1; i < n; ++i) 
    {
        position *= 2; // revient a multiplier un binaire 1(1) -> 10(2) -> 100(4) ect...
    }

    
    return (value / position) % 2; 
}


int main(void)
{
printf("%d\n", is_set(24, 4));
printf("%d\n", is_set(24, 3));
}
