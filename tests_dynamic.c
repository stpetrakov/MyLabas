#include "tests_dynamic.h"

double dynamic_test_1() {
    DynamicStack *st = stack_ctr (1, sizeof(int));

    clock_t start_time = clock();

    for (int i = 0; i < 1e6; i++) {
        push (st, &i);
    }
    int num = 1e6;

    while (num >= 1e5) {
        num /= 2;
        for (int i = 0; i < num; i++) {
            pop (st);
        }
        for (int i = 0; i < num/2; i++) {
            push (st, &i);
        }
    }

    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    stack_dtr (st);
    return elapsed_time;
}

double dynamic_test_2() {
    DynamicStack* st = stack_ctr(1, sizeof(int));

    clock_t start_time = clock();

    for (int i = 0; i < 1e6; i++) {
        push (st, &i);
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; i < 10000; i++) {
            pop (st);
        }

        for (int j = 0; i < 10000; i++) {
            push (st, &i);
        }
    }

    int num = 1e6;

    while (num >= 1e5) {
        num /= 2;
        for (int i = 0; i < num; i++) {
            pop (st);
        }
        for (int i = 0; i < num/2; i++) {
            push (st, &i);
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; i < 10000; i++) {
            pop (st);
        }

        for (int j = 0; i < 10000; i++) {
            push (st, &i);
        }
    }

    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    stack_dtr (st);
    return elapsed_time;
}

double dynamic_test_3() {
    DynamicStack* st = stack_ctr (1, sizeof(int));
    srand (time(NULL));

    for (int i = 0; i < 1e6; i++) {
        push (st, &i);
    }
    clock_t start_time = clock();

    for (int i = 0; i < 1e6; i++) {
        int x = rand()%2 + 1;
        if (x == 2) {
            pop (st);
        }
        else {
            push (st, &x);
        }
    }

    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    stack_dtr (st);
    return elapsed_time;
}

double dynamic_test_4 (int number) {
    DynamicStack *st = stack_ctr (1, sizeof(int));

    clock_t start_time = clock();

    for (int i = 0; i < number; i++) {
        push (st, &i);
    }

    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    stack_dtr (st);
    return elapsed_time;
}