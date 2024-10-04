CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic -Wvla -fsanitize=address -g3 -lcriterion
LDFLAGS=-fsanitize=address
LDLIBS=-lcriterion
SRC=test/tinyprintf.c testsuite/testing.c
OBJ=$(SRC:c=.o)

all: check

check: testsuite
	./testsuite

testsuite: $(OBJ)
	$(CC) $(CFLAGS) -o  $@ $^ $(LDFLAGS) $(LDLIBS)


