CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -g
SRC = main.c count_words.c
OBJ = ${SRC:.c=.o}


count_words: $(OBJ)

clean: 
	rm -f *.o
