#include <stdio.h>

int main(void)
{
    int x = 42;
    int *ptr_x = &x;
    printf("%d\n", x); /* show the value of x */
    printf("%p\n", &x); /* show the address of x */
    printf("%p\n", ptr_x); /* shows the value of ptr_x (which is the address of x) */
    printf("%d\n", *ptr_x); /* shows the value of what ptr_x points to: x */
    return 0;
}
