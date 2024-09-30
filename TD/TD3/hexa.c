#include <stdio.h>

void print_hexa(int number){
   printf("0x");
   printf("%08x\n", number);
} 


int main(void){
    print_hexa(42);
    print_hexa(1024);
    print_hexa(0);
}
