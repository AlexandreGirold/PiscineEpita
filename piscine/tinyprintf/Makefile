CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -fsanitize=address -g3 #--coverage -fPIC
LDFLAGS=-fsanitize=address #--coverage
LDLIBS=-lcriterion #-lgcov
SRC=src/tinyprintf.c tests/testing.c
OBJ=${SRC:.c=.o}

all: 
	$(CC) $(CFLAGS) -c -o src/tinyprintf.o src/tinyprintf.c

	
check: testsuite
	./testsuite


testsuite: ${OBJ}
	$(CC) $(CFLAGS) -c -o tests/testing.c tests/testing.o
	$(CC) $(LDLIBS) $(CFLAGS) tests/testing.o src/tinyprintf.o -o testsuite

main: 
	$(CC) ${CFLAGS} ${SRC} -o $@

OUT = main

.PHONY : all clean

clean:
	$(RM) *.o testsuite tests/*.o src/*.o src/*.gcno src/*.gcda tests/*.gcno tests/*.gcda

