#ifndef LIST_H
#define LIST_H

#include <stddef.h>

struct list
{
    int data;
    struct list *next;
};

/*
** Insert a node containing `value` at the beginning of the list.
** Return `NULL` if an error occured.
*/
struct list *list_prepend(struct list *list, int value);

/*
** Return the lenght of the list.
** Return `0` if the list is empty.
*/
size_t list_length(struct list *list);

/*
** Display the list contents on `stdout`.
** Nothing is displayed if the list is empty.
*/
void list_print(struct list *list);

/*
** Release the memory used by the list.
** Does nothing if `list` is `NULL`.
*/
void list_destroy(struct list *list);

#endif /* !LIST_H */
