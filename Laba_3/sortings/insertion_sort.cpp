#include "square_sortings.h"

void insertion_sort(int* a, const size_t n)
{
    int t, j;
    for (size_t i = 1; i < n; i++) {
        t = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > t) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        
        a[j + 1] = t;
    }
}