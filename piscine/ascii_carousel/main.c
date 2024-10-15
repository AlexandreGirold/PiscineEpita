#include <stdio.h>

#include "ascii_carousel.h"

int main(void)
{
    char in[] = "Shhh ShE is ZZZzZ059%";
    printf("In: %s\n", in);
    rot_x(in, 13);
    printf("Out: %s\n", in);
    return 0;
}
