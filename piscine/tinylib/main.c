#include "include/libstream.h"
#include <stdio.h>
#include <string.h>

int main() {
    struct stream *s;
    int c;

    // Test lbs_fopen and lbs_fputc
    s = lbs_fopen("testfile.txt", "w");
    if (!s) {
        perror("lbs_fopen");
        return 1;
    }
    
    const char *test_str = "Hello, World!\n";
    for (size_t i = 0; i < strlen(test_str); i++) {
        if (lbs_fputc(test_str[i], s) == LBS_EOF) {
            perror("lbs_fputc");
            lbs_fclose(s);
            return 1;
        }
    }
    
    if (lbs_fclose(s) == LBS_EOF) {
        perror("lbs_fclose");
        return 1;
    }

    // Test lbs_fopen and lbs_fgetc
    s = lbs_fopen("testfile.txt", "r");
    if (!s) {
        perror("lbs_fopen");
        return 1;
    }

    while ((c = lbs_fgetc(s)) != LBS_EOF) {
        putchar(c);
    }
    
    if (lbs_fclose(s) == LBS_EOF) {
        perror("lbs_fclose");
        return 1;
    }

    return 0;
}
