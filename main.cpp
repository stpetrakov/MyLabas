#include "tests/tests_generator.h"
#include "tests/testing.h"
#include "sortings/all_sortings.h"
using SortFunction = void (*)(int *, int);

int main() {
    const char* test_dir = "tests/big_tests";
    const char* output_dir = "tests/big_tests";
    const char* function_name = "recursive_merge_sort";

    int from = 10000;
    int to = 1000000;
    int step = 10000;
/*
    if (strcmp (function_name, "heap_sort") == 0)
        test_heap(test_dir, function_name, output_dir, from, to, step);
*/
    
        SortFunction sort_function = &recursive_merge_sort;
        
        test_sorting (test_dir, sort_function, function_name, output_dir, from, to, step);
    

    return 0;
}
