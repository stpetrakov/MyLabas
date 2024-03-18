#include "tests_list.h"

double list_test_1() {
    ListStack *st = stack_create();

    clock_t start_time = clock();

    for (int i = 0; i < 1e6; i++) {
        stack_push (st, &i);
    }
    int num = 1e6;

    while (num >= 1e5) {
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

double list_test_2() {
    ListStack *st = stack_create();

    clock_t start_time = clock();

    for (int i = 0; i < 1e6; i++) {
        stack_push (st, &i);
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; i < 10000; i++) {
            stack_pop (st);
        }

        for (int j = 0; i < 10000; i++) {
            stack_push (st, &i);
        }
    }

    int num = 1e6;

    while (num >= 1e5) {
        num /= 2;
        for (int i = 0; i < num; i++) {
            stack_pop (st);
        }
        for (int i = 0; i < num/2; i++) {
            stack_push (st, &i);
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; i < 10000; i++) {
            stack_pop (st);
        }

        for (int j = 0; i < 10000; i++) {
            stack_push (st, &i);
        }
    }

    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    stack_del (st);
    return elapsed_time;
}

double list_test_3() {
    ListStack *st = stack_create();

    srand (time(NULL));

    for (int i = 0; i < 1e6; i++) {
        stack_push(st, &i);
    }

    clock_t start_time = clock();

    for (int i = 0; i < 1e6; i++) {
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

double list_test_4 (int number) {
    ListStack *st = stack_create();

    clock_t start_time = clock();

    for (int i = 0; i < number; i++) {
        stack_push (st, &i);
    }

    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    stack_del(st);
    return elapsed_time;
}