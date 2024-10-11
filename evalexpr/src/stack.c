#include "evalexpr.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*struct stack *init(void)
{
    struct stack *s = malloc(sizeof(struct stack));
    if (!s)
        return NULL; //TODO Make sure error is correct
    s->next = NULL;
    s->token = NULL;
    return s;
}*/

struct stack *stack_push(struct stack *s, struct token t)
{
    struct stack *add = malloc(1 * sizeof(struct stack));
    add->token = t;
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
    return s->token->val;
}
