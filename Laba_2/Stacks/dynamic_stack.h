#ifndef LABA2_DYNAMIC_ARRAY_H
#define LABA2_DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define coeff 2

enum result{
    success = 1,
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