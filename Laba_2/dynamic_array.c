#include "dynamic_array.h"

struct DynamicStack* stack_ctr (size_t size, size_t element_size) {
    assert (size != 0);
    assert (element_size != 0);

    struct DynamicStack* st = (struct DynamicStack*) calloc(1, sizeof(struct DynamicStack));
    assert (st != NULL);

    st->data = (void*) calloc(size, sizeof(element_size));
    assert (st->data != NULL);

    st->Capacity = size;
    st->Size = 0;
    st->ElemSize = element_size;
    return st;
}

int push (struct DynamicStack* st, void* buffer) {
    assert (buffer != NULL);
    assert (st != NULL);
    assert (st->Capacity != 0);
    assert (st->ElemSize != 0);
    assert (st->data != NULL);

    if (st->Capacity == st->Size) {
        st->Capacity *= coeff;
        st->data = (void*) realloc (st->data, st->Capacity*st->ElemSize);

        assert (st->data != NULL);
    }

    memcpy ((char*) st->data + st->Size * st->ElemSize, buffer, st->ElemSize);
    st->Size++;
    return success;
}

int top (struct DynamicStack* st, void* buffer) {
    assert (st != NULL);
    assert (st->Capacity != 0);
    assert (st->ElemSize != 0);
    assert (st->data != NULL);

    memcpy (buffer, (char*) st->data + (st->Size-1) * st->ElemSize, st->ElemSize);
    return (success);
}

int pop (struct DynamicStack* st) {
    assert (st != NULL);
    assert (st->Capacity != 0);
    assert (st->ElemSize != 0);
    assert (st->data != NULL);

    if (st->Size == 0)
        return 0;

    st->Size--;

    if (st->Capacity / coeff >= st->Size) {
        st->Capacity /= coeff;
        st->data = (void*) realloc (st->data, st->Capacity*st->ElemSize);

        assert (st->data != NULL);
    }

    return success;
}

struct DynamicStack* stack_dtr (struct DynamicStack* st) {
    assert (st != NULL);
    assert (st->Capacity != 0);
    assert (st->ElemSize != 0);
    assert (st->data != NULL);

    free (st->data);
    free (st);
    return NULL;
}


