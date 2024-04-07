#include "list_stack.h"

struct Node* node_create (void* data, size_t element_size) {
    if (data == NULL) 
        return memory_allocation_error;

    struct Node* node = (struct Node*) calloc(1, sizeof(struct Node));

    if (node == NULL) 
        return memory_allocation_error;

    node->data = calloc (1, element_size);

    if (node->data == NULL) 
        return memory_allocation_error;

    memcpy(node->data, data, element_size);

    node->Next = NULL;

    return node;
}

void node_del (struct Node* node) {
    if (node == NULL) 
        return memory_allocation_error;

    free (node->data);
    free (node);
}

struct Stack* stack_create () {
    struct Stack* st;
    st = (struct Stack *) malloc(sizeof(struct Stack));

    if (st == NULL) 
        return memory_allocation_error;

    st->Last = NULL;
    st->Size = 0;
    return st;
}

int stack_push (struct Stack* st, void* buffer) {
    if (st == NULL) 
        return memory_allocation_error;

    if (buffer == NULL) 
        return memory_allocation_error;

    struct Node* new_node = node_create (buffer, sizeof(buffer));
    assert (new_node != NULL);

    new_node->Next = st->Last;
    st->Last = new_node;

    st->Size++;
    return success;
}

int stack_top (struct Stack* st, void* buffer) {
    if (st == NULL) 
        return memory_allocation_error;

    if (st->Last  == NULL) 
        return memory_allocation_error;
    
    memcpy (buffer, st->Last->data, sizeof (st->Last->data));

    return success;
}

int stack_pop (struct Stack* st) {
    if (st == NULL) 
        return memory_allocation_error;

    struct Node* t = st->Last;
    st->Last = st->Last->Next;
    node_del (t);
    st->Size--;
    return success;
}

struct Stack*  stack_del (struct Stack* st) {
    if (st == NULL) 
        return memory_allocation_error;

    while (st->Last != NULL) {
        struct Node* t = st->Last;
        st->Last = st->Last->Next;
        node_del (t);
    }

    free (st);

    return NULL;
}
