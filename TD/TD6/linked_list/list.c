#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "list.h"

struct list *list_prepend(struct list *list, int value)
{
    if (!list)
        return NULL;
    struct list *first = NULL;
    first  = malloc(sizeof(struct list)); // got to .h
    first->data = value;
    first->next = list; // 1st elem (because no loop)
    return first;   
    
}


size_t list_length(struct list *list)
{
    size_t len = 0;
    while (list)
    {
        len++;
        list = list->next;
    }
    return len;
}

void list_destroy(struct list *list)
{
    struct list *temp = NULL;
    while(!list)
    {
        temp = list;
        list = list->next;
        free(temp);

    }

}

void list_print(struct list *list)
{
    printf("%d", list->data);
    while (list)
    {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL");
    putchar('\n');

}

int main(void)
{
    struct list *first = NULL;
    struct list *second = NULL;
    second = malloc(sizeof(struct list));
    second->data = 51;
    second->next = NULL; // The last element is followed by an empty list
    first = malloc(sizeof(struct list));
    first->data = 42;
    first->next = second; 

    first = list_prepend(first, 7);  
    list_print(first);
    printf("%zu\n", list_length(first));
    list_destroy(first);
    
}
