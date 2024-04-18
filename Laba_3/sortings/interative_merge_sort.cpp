#include "quick_sortings.h"

void iterative_merge(int* a, int l, int m, int r, int* L, int* R) {
    int n1 = m - l + 1;
    int n2 = r - m;

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

        } 

        else {
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
}

void Iterative_merge_sort(int* a, int l, int r, int* L, int* R) {
    if (l < r) {
        int m = l + (r - l) / 2;

        Iterative_merge_sort(a, l, m, L, R);
        Iterative_merge_sort(a, m + 1, r, L, R);
        iterative_merge(a, l, m, r, L, R);
    }
}

void iterative_merge_sort(int* a, const size_t n) {
    int* L = (int*) calloc(n, sizeof(int));
    assert (L != NULL);

    int* R = (int*) calloc(n, sizeof(int));
    assert (R != NULL);

    Iterative_merge_sort (a, 0, n - 1, L, R);

    free (L);
    free (R);
}
