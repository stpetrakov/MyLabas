#include "square_sortings.h"

void bubble_sort (int* a, const size_t n)
{
    for (size_t i = 0; i < n-1; i++) {
        for (size_t j = i; j < n; j++) {
            if (a[i] > a[j]) {
                swap (&a[i], &a[j], int);
            }
        }
    }
}