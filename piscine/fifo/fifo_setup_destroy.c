#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

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
