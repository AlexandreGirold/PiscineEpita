#include <stddef.h>
#include <stdio.h>
#include "variant.h"
#include <stdbool.h>

void variant_display(const struct variant *e)
{
    enum type t = e->type;
    switch(t)
    {
        case TYPE_STRING:
            printf("%s\n", e->value.str_v);
            break;
        case TYPE_FLOAT:
            printf("%f\n", e->value.float_v);
            break;
        case TYPE_INT:
            printf("%d\n", e->value.int_v);
            break;
        case TYPE_CHAR:
            printf("%c\n", e->value.char_v);
            break;
        default:
            break;
    }
}


bool variant_equal(const struct variant *left, const struct variant *right)
{
    if(left == NULL && right == NULL)
        return true;
    if(left == NULL && right != NULL)
        return false;
    if(left != NULL && right == NULL)
        return false;
    enum type L = left->type;
    enum type R = right->type;
    if (L != R)
        return false;
    switch(R)
    {
        case TYPE_STRING:
            if(right->value.str_v != left->value.str_v)
                return false;
            break;
        case TYPE_FLOAT:
             if(right->value.float_v != left->value.float_v)
                return false;
            break;
        case TYPE_INT:
             if(right->value.int_v != left->value.int_v)
                return false;
            break;
        case TYPE_CHAR:
             if(right->value.char_v != left->value.char_v)
                return false;
            break;
        default:
            break;
    }
    return true;
}

int main(void) 
{
    struct variant v1;
    v1.type = TYPE_INT;
    v1.value.int_v = 12;

    struct variant v2;
    v2.type = TYPE_FLOAT;
    v2.value.float_v = 3.14;

    struct variant v3;
    v3.type = TYPE_CHAR;
    v3.value.char_v = 'A';

    struct variant v4;
    v4.type = TYPE_STRING;
    v4.value.str_v = "Hello, world!";

    
    bool res = variant_equal(&v1, &v2);
    printf("%d\n", res);

    printf("Testing variant_display:\n");

    printf("Expected Output: 12\\n\n");
    variant_display(&v1); // Should display 12\n

    printf("Expected Output: 3.140000\\n\n");
    variant_display(&v2); // Should display 3.140000\n

    printf("Expected Output: A\\n\n");
    variant_display(&v3); // Should display A\n

    printf("Expected Output: Hello, world!\\n\n");
    variant_display(&v4); // Should display Hello, world!\n

    return 0;
}
