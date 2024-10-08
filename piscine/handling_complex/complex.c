#include "complex.h"

#include <stddef.h>
#include <stdio.h>

void print_complex(struct complex a)
{
    if (a.img >= 0)
    {
        printf("complex(%.2f + %.2fi)\n", a.real, a.img);
    }
    else
    {
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
