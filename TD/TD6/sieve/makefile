CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic

sieve: sieve.o
	$(CC) -o sieve sieve.o

sieve.o:sieve.c
	$(CC) $(CFLAGS) -c -o sieve.o sieve.c
