#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlin.h>
#include <string.>

#include "evalexpr.h"

void parser(char *str)
{
    if(!str)
        return str; //NULL
    char *p = str;
    struct stack *operator = malloc(1 * sizeof(struct stack));
    struct stack *output = malloc(1 * sizeof(struct stack));
    
    while(p)
    {   
        if(*p == 
    }
}
