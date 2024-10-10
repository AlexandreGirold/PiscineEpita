CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -I/path/to/criterion/include
LDFLAGS =  -lcriterion

#Add the rest

test: test_heap.o $(TARGET)
	$(CC) -o test $^ $(LDFLAGS)

test_heap.o: test_heap.c heap.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET) test_heap.o test
