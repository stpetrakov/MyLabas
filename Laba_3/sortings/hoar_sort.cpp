#include "quick_sortings.h"
#include "swap.h"
 
int hoar_partition (int* a, int low, int high, int pivot) {
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


 void Hoar_sort (int* a, int low, int high) {
    if (low < high) {
        int p = hoar_partition (a, low, high, a[low + (high - low) / 2]);

        Hoar_sort (a, low, p);
        Hoar_sort (a, p + 1, high);
    }
 }

void hoar_sort (int* a, const size_t n) {
    Hoar_sort (a, 0, n-1);
}