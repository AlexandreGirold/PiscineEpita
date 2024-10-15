CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -g 
LDFLAGS=-fsanitize=address
SRC = main.c replace_line.c
OBJ = ${SRC:.c=.o}

replace_line: ${OBJ}
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRC)
