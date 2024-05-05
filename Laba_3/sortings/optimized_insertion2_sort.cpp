#include "square_sortings.h"

int iterative_binary_search (int* a, int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (item == a[mid])
            return mid + 1;

        if (item > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

void optimized_insertion2_sort(int* a, const size_t n) { 
    for (size_t i = 1; i < n; ++i) {
        size_t j = i - 1;
        int selected = a[i];
 
        int loc = iterative_binary_search (a, selected, 0, j);
 
        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = selected;
    }
}
