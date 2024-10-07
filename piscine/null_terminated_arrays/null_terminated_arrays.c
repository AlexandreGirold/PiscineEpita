#include <stdio.h>
#include <err.h>
#include <errno.h>
#include <assert.h>
#include <stddef.h>

void reverse_matrix(const char ***matrix) {
    if (!matrix)
        return;

    size_t first_len = 0;
    while (matrix[first_len] != NULL)
        first_len++;

    for (size_t i = 0; i < first_len / 2; i++) 
    {
        const char **temp = matrix[i];
        matrix[i] = matrix[first_len - 1 - i];
        matrix[first_len - 1 - i] = temp;
    }

    for (size_t i = 0; i < first_len; i++) 
    {
        size_t in_len = 0;
        while (matrix[i][in_len] != NULL) 
        {
            in_len++;
        }

        for (size_t j = 0; j < in_len / 2; j++) 
        {
            const char *temp = matrix[i][j];
            matrix[i][j] = matrix[i][in_len - 1 - j];
            matrix[i][in_len - 1 - j] = temp;
        }
    }
}

int main(void) {
    
    const char *array1[] = {"1", "2", "3", NULL};
    const char *array2[] = {"4", "5", NULL};
    const char *array3[] = {"6", "7", "8", "9", NULL};
    
    const char **matrix[] = {
        array1,
        array2,
        array3,
        NULL 
    };

    
    const char ***matrix_ptr = (const char ***)matrix;

    
    printf("Original matrix:\n");
    for (size_t i = 0; matrix_ptr[i] != NULL; i++) {
        for (size_t j = 0; matrix_ptr[i][j] != NULL; j++) {
            printf("%s ", matrix_ptr[i][j]);
        }
        printf("\n");
    }


    reverse_matrix(matrix_ptr);

    printf("\nReversed matrix:\n");
    for (size_t i = 0; matrix_ptr[i] != NULL; i++) {
        for (size_t j = 0; matrix_ptr[i][j] != NULL; j++) {
            printf("%s ", matrix_ptr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
