#include "quick_sortings.h"

void heapify(int *a, int n, int i, int k) {
    int largest = i;
    for (int j = 1; j <= k; j++) {
        int child = k * i + j;
        if (child < n && a[child] > a[largest]) {
            largest = child;
        }
    }
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest, k);
    }
}

void heap_sort(int *a, const int n, int k) {
    for (int i = (n - 1) / k; i >= 0; i--) {
        heapify(a, n, i, k);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0, k);
    }
}