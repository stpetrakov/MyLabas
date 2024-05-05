#include "quick_sortings.h"
#include "swap.h"

int get_child(int i, int j, int k) {
    return k * i + j;
}

void heapify(int *a, int n, int i, int k) {
    int largest = i;
    for (int j = 1; j <= k; j++) {
        int child = get_child(i, j, k);
        
        if (child < n && a[child] > a[largest]) {
            largest = child;
        }
    }
    if (largest != i) {
        swap (a[i], a[largest]);
        heapify(a, n, largest, k);
    }
}

void heap_sort(int *a, size_t n, int k) {
    for (int i = (n - 1) / k; i >= 0; i--) {
        heapify(a, n, i, k);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap (a[0], a[i]);
        heapify(a, i, 0, k);
    }
}