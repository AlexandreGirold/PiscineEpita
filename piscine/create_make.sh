#!/bin/sh

if [ "$#" -ne 1 ]; then
    echo " Provide 1 argument (name of folder)"
else
    touch "$1"/Makefile

    echo 'CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic -Wvla -fsanitize=address -g
LDLIBS=-lcriterion 
SRC=$1.c test.c
OBJ=${SRC:.c=.o}

all: 
    $(CC) $(CFLAGS) -c -o $1.o $1.c

check: testsuite
    ./test

testsuite: ${OBJ}
    $(CC) $(CFLAGS) -c -o testing.c testing.o
	$(CC) $(LDLIBS) $(CFLAGS) testing.o $1.o -o testsuite

main: 
	$(CC) ${CFLAGS} ${SRC} -o $@

OUT = main

.PHONY : all clean

clean:
	$(RM) *.o test'>$1/Makefile
fi

