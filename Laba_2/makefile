CC = gcc
CFLAGS = -c -Wall -std=c11
OBJ = main.o tests.o
EXE = result.exe

ifdef WITHOUT_DYNAMIC_STACK
    OBJ := $(filter-out Stacks/dynamic_stack.o, $(OBJ))
else
    OBJ += Stacks/dynamic_stack.o
endif

ifdef WITHOUT_LIST_STACK
    OBJ := $(filter-out Stacks/list_stack.o, $(OBJ))
else
    OBJ += Stacks/list_stack.o
endif

all: start

start: $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

main.o: main.c
	$(CC) $(CFLAGS) main.c

tests.o: Tests/tests.c
	$(CC) $(CFLAGS) Tests/tests.c

clean:
	rm -rf $(OBJ) $(EXE)
