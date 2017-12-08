OBJS_TEST = test_Tree.o
CC = g++
CFLAGS = -c -Wall -Werror -pedantic -std=c++11

all : test_Tree

test_Tree : $(OBJS_TEST)
	$(CC) $(OBJS_TEST) -o test_Tree

test_Tree.o : test_Tree.cpp Tree.hpp
	$(CC) $(CFLAGS) test_Tree.cpp

clean:
	\rm -rf *.o
