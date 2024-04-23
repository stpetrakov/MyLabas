#include "square_sortings.h"

int binarySearch1(int* a, int item, int low, int high)
{
    int mid;
    
    while (low <= high) {
        mid = low + (high - low) / 2;

        if (item == a[mid])
            return mid + 1;

        if (item > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

void optimized_insertion2_sort(int* a, const size_t n)
{
    int i, loc, j, selected;
 
    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];
 
        loc = binarySearch1(a, selected, 0, j);
 
        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = selected;
    }
}
