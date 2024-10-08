#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int merge_files(const char *file_1, const char *file_2)
{
    FILE *src_file = fopen(file_2, "r");
    if (src_file == NULL)
    {
        return -1;
    }

    FILE *dest_file = fopen(file_1, "a");
    if (dest_file == NULL)
    {
        fclose(src_file);
        return -1;
    }

    int c;
    while ((c = fgetc(src_file)) != EOF)
    {
        if (fputc(c, dest_file) == EOF)
        {
            fclose(src_file);
            fclose(dest_file);
            return -1;
        }
    }

    fclose(src_file);
    fclose(dest_file);
    return 0; // Success
}
