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

/*
** Append a node containing `value` at the end of the list.
** Return `NULL` if an error occured.
*/
struct list *list_append(struct list *list, int value);

/*
** Insert a node containing `value` at the index `index` in the list.
** If the index is greater than the length of the list, the behaviour is the
** same as `list_append`.
** Return `NULL` if an error occured.
*/
struct list *list_insert(struct list *list, int value, size_t index);

/*
** Remove the element at the index `index`.
** Return `NULL` if an error occured.
*/
struct list *list_remove(struct list *list, size_t index);

/*
** Return the position of the first node containing `value`.
** Return `-1` if nothing is found.
*/
int list_find(struct list *list, int value);

/*
** Concatenate the list `list2` at the end of the list `list`.
** Return `list2` if `list` is `NULL`.
*/
struct list *list_concat(struct list *list, struct list *list2);

/*
** Sort the elements of the list in ascending order.
** Return the new list.
*/
struct list *list_sort(struct list *list);

/*
** Invert the order of the elements of the list.
** Return the new list.
*/
struct list *list_reverse(struct list *list);

/*
** Split the list at index `index`.
** First part goes in `list` and contains the element at `index`.
** Second part is returned.
** Return `NULL` if `list` is `NULL` or `index` is invalid.
*/
struct list *list_split(struct list *list, size_t index);

#endif /* !LIST_H */
