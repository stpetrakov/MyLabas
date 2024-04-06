CC = gcc
CFLAGS = -c -Wall -std=c11


all: start
start: main.o dynamic_stack.o list_stack.o tests.o
	$(CC) main.o dynamic_stack.o list_stack.o tests.o -o result.exe

main.o: main.c
	$(CC) $(CFLAGS) main.c

dynamic_stack.o: Stacks/dynamic_stack.c
	$(CC) $(CFLAGS) Stacks/dynamic_stack.c

list_stack.o: Stacks/list_stack.c
	$(CC) $(CFLAGS) Stacks/list_stack.c

tests.o: Tests/tests.c
	$(CC) $(CFLAGS) Tests/tests.c


clean:
	rm -rf *.o start