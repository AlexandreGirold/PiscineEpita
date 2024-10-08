#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char file_name[] = "readme.txt";
    int fd = open(file_name, O_WRONLY);

    if (fd == -1)
    {
        printf("%s\n","failed to open file");
        return -1;
    }

    char *text = "Hello world, again!\n";
    char *buf[100] = {0};
    ssize_t out = read(fd, buf, strlen(text));
    close(fd);
    perror("error mess");
    return out;
}
