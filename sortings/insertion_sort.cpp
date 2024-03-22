#include "all_sortings.h"

void insertion_sort(int* a, int n)
{
    int t, j;
    for (int i = 1; i < n; i++) {
        t = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > t) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        
        a[j + 1] = t;
    }
}