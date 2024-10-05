#include <stddef.h>
#include <stdio.h>



struct complex {
    float real;
    float img;
};


#include <stdio.h>
//#include "complex.h"


void print_complex(struct complex a) {
    if (a.img >= 0) {
        printf("complex(%.2f + %.2fi)\n", a.real, a.img);
    } else {
        printf("complex(%.2f - %.2fi)\n", a.real, -a.img);
    }
}


struct complex neg_complex(struct complex a) 
{
    struct complex result;
    result.real = -a.real;
    result.img = -a.img;
    return result;
}


struct complex add_complex(struct complex a, struct complex b) 
{
    struct complex result;
    result.real = a.real + b.real;
    result.img = a.img + b.img;
    return result;
}


struct complex sub_complex(struct complex a, struct complex b) 
{
    struct complex result;
    result.real = a.real - b.real;
    result.img = a.img - b.img;
    return result;
}


struct complex mul_complex(struct complex a, struct complex b) 
{
    struct complex result;
    result.real = a.real * b.real - a.img * b.img;
    result.img = a.real * b.img + a.img * b.real;
    return result;
}


struct complex div_complex(struct complex a, struct complex b) 
{
    struct complex result;
    float denominateur = b.real * b.real + b.img * b.img;
    result.real = (a.real * b.real + a.img * b.img) / denominateur;
    result.img = (a.img * b.real - a.real * b.img) / denominateur;
    return result;
}


int main() 
{
    struct complex z1 = {3.0f, 4.0f};
    struct complex z2 = {1.0f, -2.0f};

    printf("z1: ");
    print_complex(z1);
    
    printf("z2: ");
    print_complex(z2);

    struct complex sum = add_complex(z1, z2);
    printf("z1 + z2: ");
    print_complex(sum);
}    
