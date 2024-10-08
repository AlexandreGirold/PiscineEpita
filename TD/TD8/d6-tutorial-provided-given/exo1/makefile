CC = gcc
CFLAGS =  -std=c99 -Wall -Wextra -Werror -pedantic -Wvla 

SRC = main.c hello_world.c

OBJS = ${SRC:.c=.o}

all: main

main:
	gcc ${CFLAGS} ${SRC} -o $@ 


OUT = main


.PHONY: all clean
