#include "tests.h"

#ifndef IS_ARRAY_STACK
#include "list_stack.h"

struct Node* node_create (void* data, size_t element_size) {
    assert (data != NULL);

    struct Node* node = (struct Node*) calloc(1, sizeof(struct Node));
    assert (node != NULL);

    node->data = calloc (1, element_size);
    assert(node->data != NULL);

    memcpy(node->data, data, element_size);

    node->Next = NULL;

    return node;
}

void node_del (struct Node* node) {
    assert (node != NULL);

    free (node->data);
    free (node);
}

struct Stack* stack_create () {
    struct Stack* st;
    st = (struct Stack *) malloc(sizeof(struct Stack));

    assert (st != NULL);

    st->Last = NULL;
    st->Size = 0;
    return st;
}

int stack_push (struct Stack* st, void* buffer) {
    assert (st != NULL);
    assert (buffer != NULL);

    struct Node* new_node = node_create (buffer, sizeof(buffer));
    assert (new_node != NULL);

    new_node->Next = st->Last;
    st->Last = new_node;

    st->Size++;
    return success;
}

int stack_top (struct Stack* st, void* buffer) {
    assert (st != NULL);
    assert (st->Last != NULL);
    
    memcpy (buffer, st->Last->data, sizeof (st->Last->data));

    return success;
}

int stack_pop (struct Stack* st) {
    assert (st != NULL);

    struct Node* t = st->Last;
    st->Last = st->Last->Next;
    node_del (t);
    st->Size--;
    return success;
}

struct Stack*  stack_del (struct Stack* st) {
    assert (st != NULL);

    while (st->Last != NULL) {
        struct Node* t = st->Last;
        st->Last = st->Last->Next;
        node_del (t);
    }

    free (st);

    return NULL;
}

#endif