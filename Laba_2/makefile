CC = gcc
CFLAGS = -c -Wall -std=c11

all: start

ifndef IS_ARRAY_STACK
start: main.o dynamic_stack.o tests.o
	$(CC) main.o dynamic_stack.o tests.o -o result.exe

main.o: main.c
	$(CC) $(CFLAGS) main.c

dynamic_stack.o: dynamic_stack.c
	$(CC) $(CFLAGS) dynamic_stack.c

tests.o: tests.c
	$(CC) $(CFLAGS) tests.c

else
start: main.o list_stack.o tests.o
	$(CC) main.o list_stack.o tests.o -o result.exe

main.o: main.c
	$(CC) $(CFLAGS) main.c

list_stack.o: list_stack.c
	$(CC) $(CFLAGS) list_stack.c

tests.o: tests.c
	$(CC) $(CFLAGS) tests.c

endif

clean:
	rm -rf *.o start