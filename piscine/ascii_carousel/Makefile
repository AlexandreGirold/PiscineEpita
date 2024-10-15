CC = gcc
CFLAGS =  -std=c99 -Wall -Wextra -Werror -Wvla -g
CLIBS = -fsanitize=address
SRC = main.c rot_x.c
OBJ = $(SRC:.c=.o)

rot_x: $(OBJ)

clean :
	rm rot_x *.o
