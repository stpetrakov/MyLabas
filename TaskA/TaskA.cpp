#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct my_stack
{
    int data[10000];
    int Size;
};

void push (struct my_stack *Stack, int n) {
    int x = Stack->Size;
    Stack->data[x] = n;
    Stack->Size++;
    printf ("ok\n");
}

void pop (struct my_stack *Stack) {
    if (Stack->Size == 0) {
        printf ("error\n");
    }
    else {
        Stack->Size--;
        int x = Stack->Size;
        printf("%d\n", Stack->data[x]);
    }
}

void back (struct my_stack *Stack) {
    int x = Stack->Size;
    if (Stack->Size == 0) {
        printf ("error\n");
    }
    else
        printf("%d\n", Stack->data[x-1]);
}

void Size (struct my_stack *Stack) {
    int x = Stack->Size;
    printf ("%d\n", x);
}

void clear (struct my_stack *Stack) {
    Stack->Size = 0;
    printf ("ok\n");
}

void Exit (struct my_stack *Stack) {
    printf ("bye\n");
}

int main() {
    struct my_stack Stack;
    char a[10];
    Stack.Size = 0;
    while (1>0) {
        scanf("%s", a);

        if (strcmp(a, "push") == 0) {
            int n;
            scanf("%d", &n);
            push (&Stack, n);
        }
        else if (strcmp(a, "pop") == 0)
        {
            pop (&Stack);
        }
        else if (strcmp(a, "back") == 0)
        {
            back (&Stack);
        }
        else if (strcmp(a, "size") == 0)
        {
            Size (&Stack);
        }
        else if (strcmp(a, "clear") == 0)
        {
            clear (&Stack);
        }
        else
        {
            Exit (&Stack);
            break;
        }
    }
    return 0;
}
