CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla
SRC = src/libstream.c main.c
OBJ = $(SRC:.c=.o)
LIB = libstream.a
EXEC = test_buffering

all: $(LIB) $(EXEC)

$(LIB): $(OBJ)
	ar rcs $@ $^

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIB) $(EXEC)

.PHONY: all clean
