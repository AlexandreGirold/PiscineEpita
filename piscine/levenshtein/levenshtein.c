#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

static size_t count(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t len1 = count(s1);
    size_t len2 = count(s2);
    size_t **matrix = malloc((len1 + 1) * sizeof(size_t *));
    assert(matrix != NULL);

    for (size_t i = 0; i <= len1; i++)
    {
        matrix[i] = malloc((len2 + 1) * sizeof(size_t));
        assert(matrix[i] != NULL);
    }

    for (size_t i = 0; i <= len1; i++)
    {
        matrix[i][0] = i;
    }

    for (size_t j = 0; j <= len2; j++)
    {
        matrix[0][j] = j;
    }

    for (size_t i = 1; i <= len1; i++)
    {
        for (size_t j = 1; j <= len2; j++)
        {
            size_t cost = (s1[i - 1] != s2[j - 1]) ? 1 : 0;
            size_t deletion = matrix[i - 1][j] + 1;
            size_t insertion = matrix[i][j - 1] + 1;
            size_t substitution = matrix[i - 1][j - 1] + cost;

            if (deletion < insertion)
                matrix[i][j] = deletion;
            else
                matrix[i][j] = insertion;

            if (substitution < matrix[i][j])
                matrix[i][j] = substitution;
        }
    }

    size_t distance = matrix[len1][len2];

    for (size_t i = 0; i <= len1; i++)
        free(matrix[i]);
    free(matrix);

    return distance;
}
