#include "quick_sortings.h"
#include "swap.h"
int choose_pivot_median3 (int* a, int left, int right) {
    int mid = left + (right - left) / 2;

    if (a[left] > a[mid])
        swap (a[left], a[mid]);

    if (a[left] > a[right])
        swap (a[left], a[right]);

    if (a[mid] > a[right])
        swap (a[mid], a[right]);

    return a[mid];
}
 
int hoar_median3_partition (int* a, int low, int high) {
    int pivot = choose_pivot_median3 (a, low, high);
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i >= j)
            return j;

        swap (a[i], a[j]);
    }
}


 void Hoar_median3_sort (int* a, int low, int high) {
    if (low < high) {
        int p = hoar_median3_partition (a, low, high);

        Hoar_median3_sort (a, low, p);
        Hoar_median3_sort (a, p + 1, high);
    }
 }

void hoar_median3_sort (int* a, const size_t n) {
    Hoar_median3_sort (a, 0, n-1);
}