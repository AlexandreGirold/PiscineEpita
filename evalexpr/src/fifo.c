#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "evalexpr.h"

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, struct token t)
{
    if (fifo->size == 0)
    {
        struct list *e = malloc(sizeof(struct list));
        e->next = NULL;
        e->token = t;
        fifo->head = fifo->tail = e;
    }
    else
    {
        struct list *e = malloc(sizeof(struct list));
        e->next = NULL;
        e->token = t;
        fifo->tail->next = e;
        fifo->tail = e;
    }
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->token.val;
}

void fifo_pop(struct fifo *fifo)
{
    if (!fifo)
        return;
    struct list *temp = fifo->head;
    fifo->head = fifo->head->next;
    fifo->size--;
    free(temp);
}

void fifo_print(struct fifo *fifo)
{
    if (!fifo || fifo->size == 0)
        return;
    else
    {
        struct list *p = fifo->head;
        for (size_t i = 0; i < fifo->size; i++)
        {
            printf("%d\n", p->token.type);
            p = p->next;
        }
    }
}

struct fifo *fifo_init(void)
{
    struct fifo *f = malloc(sizeof(struct fifo));
    if (!f)
        return NULL;
    f->head = NULL;
    f->tail = NULL;
    f->size = 0;
    return f;
}

void fifo_clear(struct fifo *fifo)
{
    if (!fifo)
        return;
    while (fifo->head != NULL)
    {
        fifo_pop(fifo);
    }
}

void fifo_destroy(struct fifo *fifo)
{
    if (!fifo)
        return;
    while (fifo->head != NULL)
    {
        fifo_pop(fifo);
    }
    free(fifo);
}
