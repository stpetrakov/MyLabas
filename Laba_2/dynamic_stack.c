#include "tests.h"

#ifdef IS_ARRAY_STACK
#include "dynamic_stack.h"

struct Stack* stack_create () {

    struct Stack* st = (struct Stack*) calloc(1, sizeof(struct Stack));
    assert (st != NULL);

    st->Size = 0;
    st->ElemSize = sizeof (int);
    st->Capacity = 1;

    st->data = (void*) calloc(st->Capacity, sizeof(int));
    assert (st->data != NULL);

    return st;
}

int stack_push (struct Stack* st, void* buffer) {
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

int stack_top (struct Stack* st, void* buffer) {
    assert (st != NULL);
    assert (st->Capacity != 0);
    assert (st->ElemSize != 0);
    assert (st->data != NULL);

    memcpy (buffer, (char*) st->data + (st->Size-1) * st->ElemSize, st->ElemSize);
    return (success);
}

int stack_pop (struct Stack* st) {
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

struct Stack* stack_del (struct Stack* st) {
    assert (st != NULL);
    assert (st->Capacity != 0);
    assert (st->ElemSize != 0);
    assert (st->data != NULL);

    free (st->data);
    free (st);
    return NULL;
}

#endif
