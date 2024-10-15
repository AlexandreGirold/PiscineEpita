#include <stdio.h>

#include "fifo.h"

int main(void)
{
    struct fifo *f = fifo_init();

    printf("size = %zu \n", fifo_size(f));

    fifo_push(f, 2);
    fifo_push(f, -101);
    fifo_push(f, 20);
    fifo_push(f, 7);
    fifo_push(f, 1);

    fifo_print(f);

    fifo_pop(f);
    fifo_pop(f);

    printf("size = %zu \n", fifo_size(f));

    fifo_clear(f);

    printf("size = %zu \n", fifo_size(f));

    fifo_push(f, -101);

    printf("size = %zu \n", fifo_size(f));

    fifo_destroy(f);
    return 0;
}
