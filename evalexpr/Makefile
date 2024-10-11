CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -g
CLIBS = -fsantize=address
SRC = src/... tests/....
OBJ = ${SRC:.c=.o}

all : ${OBJ}
	$(CC) $(CFLAGS) -c -o

check : testsuite
	.\evalexpr

testsuite:


clean :
	${RM} ${OBJ} testsuite

.PHONY : all clean
