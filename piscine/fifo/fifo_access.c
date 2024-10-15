#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    if (fifo->size == 0)
    {
        struct list *e = malloc(sizeof(struct list));
        e->next = NULL;
        e->data = elt;
        fifo->head = fifo->tail = e;
    }
    else
    {
        struct list *e = malloc(sizeof(struct list));
        e->next = NULL;
        e->data = elt;
        fifo->tail->next = e;
        fifo->tail = e;
    }
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (!fifo)
        return;
    if (fifo->head == NULL)
    {
        fifo->tail = NULL;
        return;
    }
    struct list *temp = fifo->head;
    fifo->head = fifo->head->next;
    fifo->size--;
    free(temp);
}

void fifo_print(const struct fifo *fifo)
{
    if (!fifo || fifo->size == 0)
        return;
    else
    {
        struct list *p = fifo->head;
        for (size_t i = 0; i < fifo->size; i++)
        {
            printf("%d\n", p->data);
            p = p->next;
        }
    }
}
