#include "all_sortings.h"

void recursive_merge(int* a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*) calloc(n1, sizeof(int)); 
    int* R = (int*) calloc(n2, sizeof(int)); 


    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0; 
    int j = 0;
    int k = l; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }

    free (L);
    free (R);
}

void my_recursive_merge_sort(int* a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        my_recursive_merge_sort(a, l, m);
        my_recursive_merge_sort(a, m + 1, r);

        recursive_merge(a, l, m, r);
    }
}

void recursive_merge_sort(int* a, int n) {
    my_recursive_merge_sort (a, 0, n - 1);
}