#ifndef LABA2_DYNAMIC_ARRAY_H
#define LABA2_DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define compression_coeff 4
#define expansion_coeff 2

enum result{
    success = 1,
    memory_allocation_error = 2,
    zero_elem_size = 3,
    zero_capacity = 4,
};

struct Stack
{
    void* data;
    size_t Size;
    size_t Capacity;
    size_t ElemSize;
};

struct Stack* stack_create ();

struct Stack* stack_del (struct Stack* st);

int stack_push (struct Stack* st, void* buffer);

int stack_top (struct Stack* st, void* buffer);

int stack_pop (struct Stack* st);

struct Stack*  stack_del (struct Stack* st);


#endif //LABA2_DYNAMIC_ARRAY_H