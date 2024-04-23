#include "square_sortings.h"

int binarySearch(int* a, int item, int low, int high)
{
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;
 
    int mid = (low + high) / 2;
 
    if (item == a[mid])
        return mid + 1;
 
    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);
    return binarySearch(a, item, low, mid - 1);
}
 
void optimized_insertion_sort(int* a, const size_t n)
{
    int i, loc, j, selected;
 
    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];
 
        loc = binarySearch(a, selected, 0, j);
 
        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = selected;
    }
}
