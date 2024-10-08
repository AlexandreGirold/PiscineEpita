#include "stack.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *add = malloc(1 * sizeof(struct stack));
    add->data = e;
    add->next = s;
    return add;
}

struct stack *stack_pop(struct stack *s)
{
    if (!s)
        return NULL;
    if (s->next == NULL)
    {
        free(s);
        return NULL;
    }
    struct stack *temp = s;
    s = s->next;
    free(temp);
    return s;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
