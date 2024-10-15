#include "evalexpr.h"

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_integer(
    char **p) // double pointer pour modifier le pointer et pas une copie
{
    int value = 0;
    while (isdigit(**p))
    {
        value = value * 10 + (**p - '0');
        (*p)++;
    }
    return value;
}

static void handle_op_lex(char **p, struct fifo **output_queue)
{
    struct token t;
    switch (**p)
    {
    case '*':
        t.type = MULT;
        t.val = 1;
        break;
    case '/':
        t.type = DIV;
        t.val = 1;
        break;
    case '+':
        t.type = ADD;
        t.val = 0;
        break;
    case '-':
        t.type = SUB;
        t.val = 0;
        break;
    case '%':
        t.type = MOD;
        t.val = 1;
        break;
    case ')':
        t.type = PARR;
        t.val = 4;
        break;
    case '(':
        t.type = PARL;
        t.val = 4;
        break;
    default:
        t.type = POW;
        t.val = 2;
    }
    fifo_push(*output_queue, t);
    (*p)++;
}

static int my_pow(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result *= a;
        }
        a *= a;
        b /= 2;
    }
    return result;
}

static int do_math(int e2, int e1, struct token t)
{
    if (t.type == DIV && e2 == 0)
        return 3; // arithmetical error;

    switch (t.type)
    {
    case ADD:
        return e1 + e2;
    case SUB:
        return e1 - e2;
    case MULT:
        return e1 * e2;
    case DIV:
        return e1 / e2;
    case MOD:
        return e1 % e2;
    case POW:
        return my_pow(e1, e2);
    default:
        return 2;
    }
}

static void popping(struct fifo **q, struct stack **st)
{
    while(*st != NULL)
    {
        struct token popped;
        popped = peek_tok_stack(*st);
        *st = stack_pop(*st);
        fifo_push(*q, popped);
    }
}
/*static struct token unary(char **p)
{

}
*/

static int is_op(struct token token)
{
    return (token.type == ADD || token.type == SUB || token.type == MULT ||token.type == DIV || token.type == MOD || token.type == POW);
  
}

struct fifo *lex_queue(char *str)
{
    struct fifo *output_queue = fifo_init();

    char *p = str;
    while (*p != '\0')
    {
        if (isspace(*p))
        {
            // Skip whitespace
            p++;
            continue;
        }
        else if (isdigit(*p))
        {
            int value = parse_integer(&p);
            struct token t;
            t.type = INT;
            t.val = value;
            fifo_push(output_queue, t);
        }
        else if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%'
                 || *p == '^' || *p == ')' || *p == '(')
        {
            //TODO : add UNARY here
            handle_op_lex(&p, &output_queue);
        }
        else
        {
            exit(1);
        }
    }
    return output_queue;
}

int rpn(struct fifo *tok_q)
{
    if (tok_q == NULL)
        return 0;
    struct stack *st = NULL;
    struct fifo *q = tok_q;
    int res = 0;
    struct token temp_tok;
    while (q->size > 0)
    {
        if (q->head->token.type == INT)
        {
            st = stack_push(st, q->head->token); // push token INT into stack
            fifo_pop(q); // continiue in the queue
        }
        else if (q->head->token.type == ADD || q->head->token.type == SUB
                 || q->head->token.type == MULT || q->head->token.type == DIV
                 || q->head->token.type == MOD || q->head->token.type == POW)
        {
            if (st == NULL)
                return 4; // Bad arg, too many operator

            int temp1;
            temp1 = stack_peek(st);
            st = stack_pop(st);

            if (st == NULL)
                return 4; // Bad arg

            int temp2;
            temp2 = stack_peek(st);
            st = stack_pop(st);

            res = do_math(temp1, temp2, q->head->token);

            temp_tok.val = res;
            st = stack_push(st, temp_tok);
            fifo_pop(q); // continiue in the queue
        }
    }
    res = stack_peek(st);
    stack_pop(st);
    return res;
}

struct fifo *shunting_yard(struct fifo *tok_q)
{

    struct stack *st = NULL;
    struct fifo *output = fifo_init();
    struct fifo *q = tok_q;

    while (q->size > 0)
    {
        if (q->head->token.type == INT)
        {
            fifo_push(output, q->head->token);
            fifo_pop(q);
        }
        else if (q->head->token.type == ADD || q->head->token.type == SUB
                 || q->head->token.type == MULT || q->head->token.type == DIV
                 || q->head->token.type == MOD || q->head->token.type == POW
                 )
        {
            while(st != NULL && is_op(q->head->token) && stack_peek(st) > q->head->token.val)
            {
                struct token temp;
                temp = peek_tok_stack(st);
                st = stack_pop(st);
                if(temp.type != PARL)
                    fifo_push(output, temp);
            }
            st = stack_push(st, q->head->token);
            fifo_pop(q);
            
        }
        if (q->size > 0 && q->head->token.type == PARL)
        {
            st = stack_push(st, q->head->token);   
            fifo_pop(q);
        }
        if (q->size > 0 && q->head->token.type == PARR)
        {
            struct token popped;
            while(st != NULL && peek_tok_stack(st).type != PARL)
            {
                popped = peek_tok_stack(st);
                st = stack_pop(st);
                fifo_push(output ,popped);
                fifo_pop(q);
            }
            if(st != NULL)
                exit(4); //TODO :check if error correct
            st = stack_pop(st); // here popping the left bracket and not using it
                                    
        }
    }
    popping(&output, &st);
    return output;
}


