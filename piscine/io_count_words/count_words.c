#include <stddef.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int count_words(const char *file_in)
{
    FILE *src_file = fopen(file_in, "r");
    if (src_file == NULL)
    {
        return -1;
    }

    int nbr_words = 0;
    int c;
    int is_word = FALSE;
    while ((c = fgetc(src_file)) != EOF)
    {
        if ((c == ' ' || c == '\t' || c == '\n') && is_word)
        {
            nbr_words++;
            is_word = FALSE;
        }
        if (c != ' ' && c != '\t' && c != '\n')
        {
            is_word = TRUE;
        }
        else
        {
            continue;
        }
    }
    if (is_word)
        nbr_words++;
    fclose(src_file);
    return nbr_words;
}
