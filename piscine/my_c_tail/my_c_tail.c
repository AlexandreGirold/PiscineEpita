#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_c_tail.h"


static size_t length(char *s)
{
    size_t len = 0;
    char ch;
    while(read(STDIN_FILENO, &ch, 1) > 0)
    {
        if(ch == '\n')
            return null;
        len++;
    }
}



void stdintail(unsigned int n) 
{


  if (n == 0)
    return;

  // Allocate an array of pointers to hold the lines
  char **lines = calloc(n, sizeof(char *));
  if (!lines)
    return;

  int count = 0;
  size_t len = 0;
  ssize_t read;
  char *line = NULL;

  while (1) 
  {
    char ch;
    ssize_t bytes_read = read(STDIN_FILENO, &ch, 1);
    if (bytes_read <= 0)
      break;

    if (line == NULL) 
    {
      len = 16;
      line = malloc(len);
      if (!line) {
        free(lines);
        return;
      }
    } 
    else if (count % len == 0) 
    {
      len *= 2;
      char *temp = realloc(line, len);
      if (!temp) 
      {
        free(line);
        free(lines);
        return;
      }
      line = temp;
    }

    line[count++] = ch;

    if (ch == '\n') 
    {
      line[count] = '\0';

      if (lines[n - 1]) 
      {
        free(lines[0]);
        for (unsigned int i = 1; i < n; ++i) 
        {
          lines[i - 1] = lines[i];
        }
        lines[n - 1] = line;
      } else {
        for (unsigned int i = 0; i < n; ++i) 
        {
          if (!lines[i]) 
          {
            lines[i] = line;
            break;
          }
        }
      }

      line = NULL;
      count = 0;
    }
  }

  for (unsigned int i = 0; i < n; ++i) 
  {
    if (lines[i]) 
    {
      write(STDOUT_FILENO, lines[i], strlen(lines[i]));
      free(lines[i]);
    }
  }

  free(lines);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        return 1;
    }

    unsigned int n = atoi(argv[1]);
    stdintail(n);
    return 0;
}
