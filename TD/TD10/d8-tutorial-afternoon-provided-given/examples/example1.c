#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    char buffer[] = "Test.";
    char output[32];
    size_t len;
    strcpy(output, buffer);
    len = strlen(output);
    printf("%s (%zu)", output, len);
    putchar('\n');
    int fd = open("/dev/null", 0);
    close(fd);
}
