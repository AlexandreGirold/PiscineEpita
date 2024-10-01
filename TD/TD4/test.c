#include <stdio.h>
#include <stdlin.h>
#include <stddef.h>

int *toto(void)
{
    return malloc(sizeof(int));//malloc returns pointer;
}


