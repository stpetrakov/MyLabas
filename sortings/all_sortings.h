#ifndef ALL_SORTINGS_H
#define ALL_SORTINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void bubble_sort (int* a, int n);

void insertion_sort(int* a, int n);

void selection_sort(int* a, int n);

void shell_sort(int* a, int n);

void heap_sort(int* a, int n, int k);

void recursive_merge_sort(int* a, int n);

void interactive_merge_sort(int* a, int n);

#endif // ALL_SORTINGS_H
