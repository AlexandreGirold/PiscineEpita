#ifndef STACK_H
#define STACK_H

struct stack
{
    int data;
    struct stack *next;
};

struct stack *stack_push(struct stack *s, int e);
struct stack *stack_pop(struct stack *s);
int stack_peek(struct stack *s);

#include <stddef.h>

#endif /* !STACK_H */
