#ifndef EVALEXPR_H
#define EVALEXPR_H

#include <stddef.h>

struct token
{
    enum token_type type;
    enum associative ass;
    int val;
};


enum token_type
{
    SPACE = 0,
    INT = 0,
    ADD = 1,
    SUB = 1,
    MULT = 2,
    DIV = 2,
    MOD = 2,
    EXP = 3,
    UNI = 4,// unary +
    UNO = 4,// unary -
    PAR = 5,//( and )
};

enum associative
{
    left,
    right,
};

//stack related shit
struct stack
{
    struct token token;
    struct stack *next
}

struct stack *stack_push(struct stack *s, struct token);
struct stack *stack_pop(struct stack *s);
int stack_peek(struct stack *s);

//queue related shit
struct list
{
    struct token token;
    struct list *next;
};

struct fifo
{
    struct list *head;
    struct list *tail;
    size_t size;
};

struct fifo *fifo_init(void);
size_t fifo_size(struct fifo *fifo);
void fifo_push(struct fifo *fifo, struct token t);
int fifo_head(struct fifo *fifo);
void fifo_pop(struct fifo *fifo);
void fifo_clear(struct fifo *fifo);
void fifo_destroy(struct fifo *fifo);
void fifo_print(const struct fifo *fifo);

#endif /* !EVALEXPR_H */
