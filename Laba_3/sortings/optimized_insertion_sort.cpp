#include "square_sortings.h"

int recursive_binary_search (int* a, int item, int low, int high) {
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;
 
    int mid = low + (high - low)/2;
 
    if (item == a[mid])
        return mid + 1;
 
    if (item > a[mid])
        return recursive_binary_search (a, item, mid + 1, high);
    return recursive_binary_search (a, item, low, mid - 1);
}
 
void optimized_insertion_sort(int* a, const size_t n) {
    for (size_t i = 1; i < n; ++i) {
        size_t j = i - 1;
        int selected = a[i];
 
        int loc = recursive_binary_search (a, selected, 0, j);
 
        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = selected;
    }
}
