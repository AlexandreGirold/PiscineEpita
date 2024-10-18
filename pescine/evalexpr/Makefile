CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -g #--coverage -fPIC
CLIBS = -fsanitize=address #-lgcov
SRC = src/fifo.c src/stack.c src/evalexpr.c src/main.c
OBJ = ${SRC:.c=.o}

all : $(OBJ) 
	$(CC) $(CFLAGS) $(CLIBS) ${SRC} -o evalexpr 

check : 
	bash tests/testsuite.sh

#testsuite:


clean :
	${RM} ${OBJ} testsuite evalexpr

.PHONY : all clean
