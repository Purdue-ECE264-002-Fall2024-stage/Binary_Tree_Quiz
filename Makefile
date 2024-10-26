CC = gcc
CFLAGS = -std=c11 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = binarytree

SRC_DIR = .
TEST_DIR = binary_trees
SRCS = main.c helper.c
OBJS = $(SRCS:%.c=%.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

test1: $(EXEC)
	./$(EXEC) $(TEST_DIR)/trace1.txt

memcheck: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC) $(TEST_DIR)/trace1.txt

clean: 
	rm -f binarytree *.o output?? *~