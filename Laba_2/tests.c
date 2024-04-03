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
    printf ("%f ", (end_time - start_time));
    double elapsed_time = ((end_time - start_time));
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
    if (test != 4) {
    
    double med = 0;

    for (int i = 0; i < number_of_tests; i++) {
        if (test == 1)
            double result = test_1();
        
        else if (test == 2)

        else if (test == 3)

        printf ("%lg ", result);
        med += result;
    }

    printf ("%lg\n", med);
    }

    else {
        for (int i = 1000; i <= 1e6; i += 1000) {
            printf("%lg,\n", list_test_4 (i));
        }
   }
}