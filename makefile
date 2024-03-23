CC = gcc
CFLAGS = -c -Wall -std=c11

all: start

start: main.o dynamic_array.o list_stack.o tests_dynamic.o tests_list.o
	$(CC) main.o dynamic_array.o list_stack.o tests_dynamic.o tests_list.o -o result.exe

main.o: 
	main.c
	$(CC) $(CFLAGS) main.c

dynamic_array.o: 
	dynamic_array.c
	$(CC) $(CFLAGS) dynamic_array.c


list_stack.o: 
	list_stack.c
	$(CC) $(CFLAGS) list_stack.c


tests_dynamic.o: 
	tests_dynamic.c
	$(CC) $(CFLAGS) tests_dynamic.c


tests_list.o: 
	tests_list.c
	$(CC) $(CFLAGS) tests_list.c

clean:
	rm -rf *.o start