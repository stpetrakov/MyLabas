#include "tests/testing.h"
#include "tests/tests_generator.h"

#include "sortings/counting_sortings.h"
#include "sortings/square_sortings.h"
#include "sortings/quick_sortings.h"

typedef void (*SortFunction)(int *, size_t);

#define SORT_FUNCTION(name) \
    if (strcmp(function_name, #name) == 0) { \
        sort_function = &name; \
        break; \
    }

const int FROM_BIG = 10000;
const int TO_BIG = 1000000;
const int STEP_BIG = 10000;

const int FROM_SMALL = 50;
const int TO_SMALL = 1000;
const int STEP_SMALL = 50;

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
        SORT_FUNCTION(optimized_insertion_sort);
        SORT_FUNCTION(optimized_insertion2_sort);
        break;
    }

    int FROM = 10000;
    int TO = 1000000;
    int STEP = 10000;

    if (strcmp (test_dir, "tests/small_tests") == 0) {
        test_sorting (test_dir, sort_function, function_name, output_dir, FROM_SMALL, TO_SMALL, STEP_SMALL);
    }

    if (strcmp (function_name, "heap_sort") == 0)
        test_heap(test_dir, function_name, output_dir, FROM_BIG, TO_BIG, STEP_BIG);
    
    else {  
        test_sorting (test_dir, sort_function, function_name, output_dir, FROM_BIG, TO_BIG, STEP_BIG);
    }
    

    return 0;
}
