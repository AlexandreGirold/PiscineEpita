CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -Werror -Wvla -fsanitize=address -g 

SRCS = add.c create.c del.c pop.c print.c test.c

LDLIBS += -lcriterion

OBJS = $(SRCS:.c=.o)
EXEC = my_program
NAME = library 

all: $(NAME)

$(NAME): $(OBJS)
	 ar rcs libheap.a $(OBJS) 

#%.o: %.c heap.h
#	$(CC) $(CFLAGS) -c $< -o $@

test: testsuite  
	./testsuite

testsuite: ${OBJS}
	$(CC) $(LDLIBS) $(CFLAGS) ${OBJS} -o testsuite


#test_heap.o: test_heap.c heap.h
#	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) libheap.a testsuite

.PHONY: all clean

