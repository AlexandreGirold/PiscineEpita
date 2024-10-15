#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <stddef.h>

typedef int (*f_cmp)(const void *, const void *);

void insertion_sort(void **array, f_cmp comp);

#endif /* !INSERTION_SORT_H */
