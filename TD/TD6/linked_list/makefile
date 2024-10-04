CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic

list: list.o
	$(CC) -o list list.o

list.o: list.c
	$(CC) $(CFLAGS) -c -o list.o list.c
