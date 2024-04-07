#ifndef LABA2_LIST_STACK_H
#define LABA2_LIST_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

enum result{
    success = 1,
    memory_allocation_error = 2,
};

struct Node {
    void* data;
    struct Node* Next;
};

struct Stack {
    struct Node* Last;
    size_t Size;
};

struct Node* node_create (void * data, size_t element_size);

struct Stack* stack_create();

int stack_push (struct Stack* st, void* buffer);

int stack_top (struct Stack* st, void* buffer);

int stack_pop (struct Stack* st);

struct Stack*  stack_del (struct Stack* st);

#endif //LABA2_LIST_STACK_H
