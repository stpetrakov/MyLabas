#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define compression_coeff 4
#define expansion_coeff 2

enum result{
    success = 1,
    error = INT_MIN
};

struct Stack {
    void* data;
    size_t Size;
    size_t Capacity;
    size_t ElemSize;
};

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
    if (buffer == NULL) 
        return error;

    if (st == NULL)
        return error;

    if (st->data == NULL)
        return error;

    if (st->Capacity == 0)
       return error;

    if (st->ElemSize == 0)
        return error;
    
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
        return error;

    if (st->data == NULL)
        return error;

    if (st->Capacity == 0)
       return error;

    if (st->ElemSize == 0)
        return error;

    memcpy (buffer, (char*) st->data + (st->Size-1) * st->ElemSize, st->ElemSize);

    return (success);
}

int stack_pop(struct Stack* st) {
    if (st == NULL)
        return INT_MIN; 

    if (st->data == NULL)
        return INT_MIN; 

    if (st->Capacity == 0)
        return INT_MIN; 

    if (st->ElemSize == 0)
        return INT_MIN; 

    if (st->Size == 0)
        return INT_MIN;  

    st->Size--;

    int popped_element;
    memcpy(&popped_element, (char*)st->data + (st->Size * st->ElemSize), st->ElemSize);

    if (st->Capacity / expansion_coeff >= st->Size) {
        st->Capacity /= expansion_coeff;
        st->data = realloc(st->data, st->Capacity * st->ElemSize);

        if (st->data == NULL)
            return INT_MIN;  
    }

    return popped_element;  
}


struct Stack* stack_del (struct Stack* st) {
    assert (st != NULL);
    assert (st->data != NULL);
    assert (st->Capacity != 0);
    assert (st->ElemSize != 0);

    free (st->data);
    free (st);

    return NULL;
}

int stack_clear (struct Stack* st) {
    assert (st != NULL);

    st->Size = 0;
    return success;
}

int main() {
    struct Stack *stack = stack_create();
    char command[10];

    while (1) {
        scanf ("%s", command);

        if (strcmp(command, "push") == 0) {
            int n;
            scanf ("%d", &n);
            if (stack_push (stack, &n) == success)
                printf ("ok\n");
        }

        else if (strcmp (command, "pop") == 0) {
            int res = stack_pop (stack);
            if (res == error) 
                printf ("error\n");

            else
                printf ("%d\n", res);
        }

        else if (strcmp(command, "back") == 0) {
            int top_element;
            stack_top (stack, &top_element);
            if (top_element == error)
                printf ("error\n");

            else
                printf ("%d\n", top_element);  
        }

        else if (strcmp(command, "size") == 0) {
            printf("%ld\n", stack->Size);
        }

        else if (strcmp(command, "clear") == 0) {
            if (stack_clear (stack) == success)
                printf ("ok\n");
        }

        else {
            stack_del (stack);
            printf ("bye\n");
            break;
        }
    }

    return 0;
}