#include "tests.h"

#ifdef IS_ARRAY_STACK
#include "dynamic_stack.h"
#else
#include "list_stack.h"
#endif

double test_1() {
    struct Stack *st = stack_create();

    clock_t start_time = clock();

    for (int i = 0; i < big; i++) {
        stack_push (st, &i);
    }
    int num = big;

    while (num >= not_big) {
        num /= 2;
        for (int i = 0; i < num; i++) {
            stack_pop (st);
        }
        for (int i = 0; i < num/2; i++) {
            stack_push (st, &i);
        }
    }

    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    stack_del(st);
    return elapsed_time;
}

double test_2() {
    struct Stack *st = stack_create();

    clock_t start_time = clock();

    for (int i = 0; i < big; i++) {
        stack_push (st, &i);
    }

    for (int i = 0; i < small; i++) {
        for (int j = 0; j < not_small; j++) {
            stack_pop (st);
        }

        for (int j = 0; j < not_small; j++) {
            stack_push (st, &i);
        }
    }

    int num = big;

    while (num >= not_big) {
        num /= 2;
        for (int i = 0; i < num; i++) {
            stack_pop (st);
        }
        for (int i = 0; i < num/2; i++) {
            stack_push (st, &i);
        }
    }

    for (int i = 0; i < small; i++) {
        for (int j = 0; j < not_small; j++) {
            stack_pop (st);
        }

        for (int j = 0; j < not_small; j++) {
            stack_push (st, &i);
        }
    }

    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    stack_del (st);
    return elapsed_time;
}

double test_3() {
    struct Stack *st = stack_create();

    srand (time(NULL));

    for (int i = 0; i < big; i++) {
        stack_push(st, &i);
    }

    clock_t start_time = clock();

    for (int i = 0; i < big; i++) {
        int x = rand()%2 + 1;
        if (x == 2) {
            stack_pop (st);
        }
        else {
            stack_push (st, &x);
        }
    }

    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    stack_del(st);
    return elapsed_time;
}

double test_4 (int number) {
    struct Stack *st = stack_create();
    clock_t start_time = clock();

    for (int i = 0; i < number; i++) {
        stack_push (st, &i);
    }

    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    stack_del(st);
    return elapsed_time;
}

void tester (int number_of_tests, int test) {
    double med = 0;
    
    for (int i = 0; i < number_of_tests; i++) {
        double result = test_1();
        printf ("%lg ", result);
        med += result;
    }

    printf ("%lg\n", med);

}