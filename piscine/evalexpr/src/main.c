#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "evalexpr.h"

int main(int argc, char *argv[])
{
    if (argc > 2)
        return 4; // other error
    int result = 0;
    // char *arr = "(1- 6)*3";
    char *arr = malloc(512);
    if (fgets(arr, 512, stdin) != NULL)
    {
        // printf("'%s'\n", arr);
        struct fifo *q = lex_queue(arr);
        // fifo_print(q);
        if (q->size == 0)
        {
            free(arr);
            free(q);
            return 0;
        }
        if (argc == 2)
            if (strcmp(argv[1], "-rpn") == 0)
                result = rpn(q);
            else
                return 4; // Other error
        else
        {
            struct fifo *output = shunting_yard(q);
            // fifo_print(output);
            result = rpn(output);
            // printf("size = %zu \n", fifo_size(q));
            free(output);
        }
        printf("%d\n", result);
        free(q);
    }

    free(arr);
    return 0;
}

/*
int main(void)
{
    int result = 0;
    char *arr = "6+6";

    struct fifo *q = lex_queue(arr);
    //fifo_print(q);

    struct fifo *output = shunting_yard(q);
    //fifo_print(output);

    result = rpn(output);
    //printf("size = %zu \n", fifo_size(q));
    free(output);
    printf("resultat :%d\n", result);
    free(q);


}*/
