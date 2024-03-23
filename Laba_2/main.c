#include <stdio.h>
#include "tests_dynamic.h"
#include "tests_list.h"
#define test_number 1;
#define number of tests

int main (int argc, const char* argv[])
{
    double med_dynamic = 0;
    double med_list = 0;

    int i = 0;
    for (i = 0; i < tests; i++) {
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
