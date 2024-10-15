#define _POSIX_C_SOURCE 200809L
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)
{
    FILE *src_file = fopen(file_in, "r");
    if (src_file == NULL)
    {
        return -1;
    }

    FILE *dest_file = fopen(file_out, "w+");
    if (dest_file == NULL)
    {
        fclose(src_file);
        return -1;
    }
    int line = 0;
    char *lineptr = NULL;
    size_t buff = 0;
    ssize_t nbr_c = 0;
    while (nbr_c != -1)
    {
        nbr_c = getline(&lineptr, &buff, src_file);
        if (line == n)
        {
            fputs(content, dest_file);
            nbr_c = getline(&lineptr, &buff, src_file);
        }
        else
            fputs(lineptr, dest_file);
        line++;
    }
    if (lineptr != NULL)
        free(lineptr);

    fclose(src_file);
    fclose(dest_file);
    return 0; // Success
}
