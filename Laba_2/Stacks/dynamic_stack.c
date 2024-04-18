#include "dynamic_stack.h"

struct Stack* stack_create () {

    struct Stack* st = (struct Stack*) calloc(1, sizeof(struct Stack));
    
    if (st == NULL)
        return memory_allocation_error;

    st->Size = 0;
    st->ElemSize = sizeof (int);
    st->Capacity = 1;

    st->data = (void*) calloc(st->Capacity, sizeof(int));



    return st;
}

int stack_push (struct Stack* st, void* buffer) {
    if (buffer == NULL) 
        return memory_allocation_error;

    if (st == NULL)
        return memory_allocation_error;

    if (st->data == NULL)
        return memory_allocation_error;

    if (st->Capacity == 0)
       return zero_capacity;

    if (st->ElemSize == 0)
        return zero_elem_size;
    
    if (st->Capacity == st->Size) {
        st->Capacity *= expansion_coeff;
        st->data = (void*) realloc (st->data, st->Capacity*st->ElemSize);

        assert (st->data != NULL);
    }

    memcpy ((char*) st->data + st->Size * st->ElemSize, buffer, st->ElemSize);
    st->Size++;
    return success;
}

int stack_top (struct Stack* st, void* buffer) {
    if (st == NULL)
        return memory_allocation_error;

    if (st->data == NULL)
        return memory_allocation_error;

    if (st->Capacity == 0)
       return zero_capacity;

    if (st->ElemSize == 0)
        return zero_elem_size;

    memcpy (buffer, (char*) st->data + (st->Size-1) * st->ElemSize, st->ElemSize);
    return (success);
}

int stack_pop (struct Stack* st) {
    if (st == NULL)
        return memory_allocation_error;

    if (st->data == NULL)
        return memory_allocation_error;

    if (st->Capacity == 0)
       return zero_capacity;

    if (st->ElemSize == 0)
        return zero_elem_size;

    if (st->Size == 0)
        return 0;

    st->Size--;

    if (st->Capacity / compression_coeff >= st->Size) {
        st->Capacity /= compression_coeff;
        st->data = (void*) realloc (st->data, st->Capacity*st->ElemSize);

        if (st->data == NULL)
            return memory_allocation_error;
    }

    return success;
}

struct Stack* stack_del (struct Stack* st) {
    if (st == NULL)
        return memory_allocation_error;

    if (st->data == NULL)
        return memory_allocation_error;

    if (st->Capacity == 0)
       return zero_capacity;

    if (st->ElemSize == 0)
        return zero_elem_size;

    free (st->data);
    free (st);
    return NULL;
}
