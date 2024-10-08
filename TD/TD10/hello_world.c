#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    //char file_name[] = "hello_world.txt";
    //int fd = open(file_name, O_RDWR);

    /*if (fd == -1)
    {
        printf("%s\n","failed to open file");
        return -1;
    }
*/
    char *text = "Hello world, again!\n";
    write(STDOUT_FILENO, text, strlen(text));
    return 0;
}
