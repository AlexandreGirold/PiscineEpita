#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void reverse_matrix(const char ***matrix)
{
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
