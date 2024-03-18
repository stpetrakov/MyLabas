#ifndef LABA2_DYNAMIC_ARRAY_H
#define LABA2_DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct DynamicStack
{
    void* data;
    size_t Size;
    size_t Capacity;
    size_t ElemSize;
};

struct DynamicStack* stack_ctr (size_t size, size_t element_size);

struct DynamicStack* stack_dtr (struct DynamicStack* st);

int push (struct DynamicStack* st, void* buffer);

int top (struct DynamicStack* st, void* buffer);

int pop (struct DynamicStack* st);


#endif //LABA2_DYNAMIC_ARRAY_H