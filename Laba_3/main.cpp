 #include "tests/tests_generator.h"
#include "tests/testing.h"
#include "sortings/all_sortings.h"
using SortFunction = void (*)(int *, int);

int main() {
    const char* test_dir = "tests/big_tests";
    const char* output_dir = "tests/big_tests";
    const char* function_name = "msd_sort";

<<<<<<< HEAD
int main(int argc, char *argv[]) {
    assert (argc != 3);

    const char *test_dir = argv[1];
    const char *output_dir = argv[2];
    const char *function_name = argv[3];

    SortFunction sort_function = NULL;

    while (true) {
        SORT_FUNCTION(bubble_sort);
        SORT_FUNCTION(hoar_sort);
        SORT_FUNCTION(insertion_sort);
        SORT_FUNCTION(iterative_merge_sort);
        SORT_FUNCTION(lomuto_sort);
        SORT_FUNCTION(lsd_sort);
        SORT_FUNCTION(msd_sort);
        SORT_FUNCTION(recursive_merge_sort);
        SORT_FUNCTION(selection_sort);
        SORT_FUNCTION(shell_sort);
        SORT_FUNCTION(thick_sort);
        SORT_FUNCTION(hoar_center_sort);
        SORT_FUNCTION(hoar_median3_sort);
        SORT_FUNCTION(hoar_median3random_sort);
        SORT_FUNCTION(hoar_random_sort);
        break;
    }

    int FROM = 10000;
    int TO = 1000000;
    int STEP = 10000;
=======
    int from = 10000;
    int to = 1000000;
    int step = 10000;
>>>>>>> parent of 1520dda (Problems Fixed)

    if (strcmp (test_dir, "tests/small_tests") == 0) {
        from = 50;
        to = 1000;
        step = 50;
    }

    if (strcmp (function_name, "heap_sort") == 0)
        test_heap(test_dir, function_name, output_dir, from, to, step);
    
    else {
        SortFunction sort_function = &msd_sort;    
        test_sorting (test_dir, sort_function, function_name, output_dir, from, to, step);
    }
    

    return 0;
}
