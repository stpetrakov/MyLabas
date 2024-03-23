#ifndef LABA2_LIST_STACK_H
#define LABA2_LIST_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

enum result{
    success = 1,
};

struct Node {
    void* data;
    struct Node* Next;
};

struct ListStack {
    struct Node* Last;
    size_t Size;
};

struct Node* node_create (void * data, size_t element_size);

struct ListStack* stack_create();


int stack_push (struct ListStack* st, void* buffer);

int stack_top (struct ListStack* st, void* buffer);

int stack_pop (struct ListStack* st);

struct ListStack*  stack_del (struct ListStack* st);

#endif //LABA2_LIST_STACK_H
