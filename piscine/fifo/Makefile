CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Wvla -fsanitize=address -g
SRC = fifo_access.c fifo_setup_destroy.c 
LDFLAGS=-fsanitize=address
OBJ = ${SRC:.c=.o}
NAME = library

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs libfifo.a $(OBJ)

main: $(OBJ) main.o
	$(CC) $(CFLAGS) -o out $^ 

clean :
	rm *.o out libfifo.a 
