#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char file_name[] = "755.txt";
    int fd = open(file_name,O_CREAT, 0755);

    if (fd == -1)
    {
        printf("%s\n","failed to open file");
        return -1;
    }

    close(fd);
    perror("error mess");
    return 0;
}
