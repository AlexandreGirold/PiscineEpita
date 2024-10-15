#ifndef EVALEXPR_H
#define EVALEXPR_H

#include <stddef.h>

enum associative
{
    NONE,
    LEFT,
    RIGHT,
};

enum token_type
{
    INT,
    ADD,
    SUB,
    MULT,
    DIV,
    MOD,
    POW,
    UNI, // unary +
    UNO, // unary -
    PARR, //)
    PARL,
};


struct token
{
    enum token_type type;
    enum associative ass;
    int val;
};

// stack related shit
struct stack
{
    struct token token;
    struct stack *next;
};

struct stack *stack_push(struct stack *s, struct token);
struct stack *stack_pop(struct stack *s);
int stack_peek(struct stack *s);
struct token peek_tok_stack(struct stack *s);

// queue related shit
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

// fifo
struct fifo *fifo_init(void);
size_t fifo_size(struct fifo *fifo);
void fifo_push(struct fifo *fifo, struct token t);
int fifo_head(struct fifo *fifo);
void fifo_pop(struct fifo *fifo);
void fifo_clear(struct fifo *fifo);
void fifo_destroy(struct fifo *fifo);
void fifo_print(struct fifo *fifo);
// had const before struct
// main function
struct fifo *lex_queue(char *str);
int rpn(struct fifo *tok_q);
struct fifo *shunting_yard(struct fifo *tok_q);
#endif /* !EVALEXPR_H */
