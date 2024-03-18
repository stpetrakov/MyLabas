#include "list_stack.h"

struct Node* node_create (void* data, size_t element_size) {
    assert (data != NULL);

    Node* node = (struct Node*) calloc(1, sizeof(struct Node));
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

struct ListStack* stack_create () {
    struct ListStack* st;
    st = (struct ListStack *) malloc(sizeof(struct ListStack));

    assert (st != NULL);

    st->Last = NULL;
    st->Size = 0;
    return st;
}

int stack_push (struct ListStack* st, void* buffer) {
    assert (st != NULL);
    assert (buffer != NULL);

    struct Node* new_node = node_create (buffer, sizeof(buffer));
    //printf("%d ", *(int*) new_node->data);
    assert (new_node != NULL);

    new_node->Next = st->Last;
    st->Last = new_node;

    st->Size++;
    return 1;
}

int stack_top (struct ListStack* st, void* buffer) {
    assert (st != NULL);
    assert (st->Last != NULL);
    memcpy (buffer, st->Last->data, sizeof(st->Last->data));
    return *(int*)(st->Last)->data;
}

int stack_pop (struct ListStack* st) {
    assert (st != NULL);

    struct Node* t = st->Last;
    st->Last = st->Last->Next;
    node_del (t);
    st->Size--;
    return 1;
}

struct ListStack*  stack_del (struct ListStack* st) {
    assert (st != NULL);

    while (st->Last != NULL) {
        struct Node* t = st->Last;
        st->Last = st->Last->Next;
        node_del (t);
    }

    free (st);

    return NULL;
}

