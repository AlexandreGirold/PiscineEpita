#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "evalexpr.h"


int parse_integer(char **p) //double pointer pour modifier le pointer et pas une copie
{
    int value = 0;
    while (isdigit(**p)) {
        value = value * 10 + (**p - '0');
        (*p)++;
    }
    return value;
}

void handle_operator(char op, struct stack **operatorStack)

void parser(char *str)
{
    if(!str)
        return; //NULL

    struct stack *operatorStack = NULL; 
    struct fifo *outputQueue = fifo_init(); 

    char *p = str;
    while (*p != '\0') 
    {
        if (isspace(*p)) {
            // Skip whitespace
            p++;
            continue;
        }
        if (isdigit(*p)) 
        {
            int value = parse_integer(&p);
            struct token t;
            t.type = INT;
            t.val = value;
            fifo_push(outputQueue, t);
        }
        

}
