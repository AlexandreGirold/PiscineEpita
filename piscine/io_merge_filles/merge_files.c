#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

int merge_files(const char *file_1, const char *file_2) {
    FILE *src_file = fopen(file_2, "r");
    if (src_file == NULL) {
        return -1; // Error opening file_2
    }

    FILE *dest_file = fopen(file_1, "a");
    if (dest_file == NULL) {
        fclose(src_file);
        return -1; // Error opening file_1
    }

    int c;
    while ((c = fgetc(src_file)) != EOF) {
        if (fputc(c, dest_file) == EOF) {
            fclose(src_file);
            fclose(dest_file);
            return -1; // Error writing to file_1
        }
    }

    if (ferror(src_file)) {
        fclose(src_file);
        fclose(dest_file);
        return -1; // Error reading file_2
    }

    fclose(src_file);
    fclose(dest_file);
    return 0; // Success
}
