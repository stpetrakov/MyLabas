#ifndef TESTING_H
#define TESTING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

enum status {
    arrays_not_equal = 0,
    arrays_equal = 1
};

int compare_arrays(const int *a, const int *b, int size);

void read_array_from_file(const char *filename, int *array, int size);

void record_results (const double* execution_times, const char* ans, const int num_tests);

void test_sorting(const char* test_dir, void (*sort_function)(int* , int), const char* function_name, const char* output_dir, int from, int to, int step);

void test_heap(const char* test_dir, const char* function_name, const char* output_dir, int from, int to, int step);

#endif // TESTING_H
