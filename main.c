#include <stdio.h>
#include "tests_dynamic.h"
#include "tests_list.h"

int main (int argc, const char* argv[])
{
    //for 1-3 tests
    int tests;
    scanf ("%d", &tests);

    double med_dynamic = 0;
    double med_list = 0;

    for (int i = 0; i < tests; i++) {
        double result = dynamic_test_3();
        printf ("%lg ", result);
        med_dynamic += result;

        result = list_test_3();
        printf ("%lg\n", result);
        med_list += result;
    }

    printf ("Average value of dynamic: %lg list: %lg", med_dynamic/(double)tests, med_list/(double)tests);

    //for 4 test

    /*
    for (int i = 1000; i <= 1e6; i += 1000) {
        printf("%lg,\n", list_test_4 (i));
    }
    */
}