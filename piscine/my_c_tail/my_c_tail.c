#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void stdintail(unsigned int n) {
    if (n == 0) return;

    // Allocate an array of pointers to hold the lines
    char **lines = (char **)calloc(n, sizeof(char *));
    if (!lines) return;

    int count = 0;
    size_t len = 0;
    ssize_t read;
    char *line = NULL;

    while (1) {
        // Read a character at a time
        char ch;
        ssize_t bytes_read = read(STDIN_FILENO, &ch, 1);
        if (bytes_read <= 0) break;

        // Allocate memory for the line if necessary
        if (line == NULL) {
            len = 16;
            line = (char *)malloc(len);
            if (!line) {
                // Handle allocation error
                free(lines);
                return;
            }
        } else if (count % len == 0) {
            len *= 2;
            char *temp = (char *)realloc(line, len);
            if (!temp) {
                // Handle allocation error
                free(line);
                free(lines);
                return;
            }
            line = temp;
        }

        // Append the read character to the line
        line[count++] = ch;

        // If the character is a newline, process the line
        if (ch == '\n') {
            line[count] = '\0'; // Null-terminate the string

            // If the buffer is full, free the oldest line
            if (lines[n-1]) {
                free(lines[0]);
                for (unsigned int i = 1; i < n; ++i) {
                    lines[i-1] = lines[i];
                }
                lines[n-1] = line;
            } else {
                for (unsigned int i = 0; i < n; ++i) {
                    if (!lines[i]) {
                        lines[i] = line;
                        break;
                    }
                }
            }

            // Reset for the next line
            line = NULL;
            count = 0;
        }
    }

    // Write the last n lines to stdout
    for (unsigned int i = 0; i < n; ++i) {
        if (lines[i]) {
            write(STDOUT_FILENO, lines[i], strlen(lines[i]));
            free(lines[i]);
        }
    }

    // Clean up
    free(lines);
}
