#include "quick_sortings.h"
#include "swap.h"

void Hoar_center_sort (int* a, int low, int high) {
    if (low < high) {
        int p = hoar_partition (a, low, high, a[low + (high - low) / 2]);

        Hoar_center_sort (a, low, p);
        Hoar_center_sort (a, p + 1, high);
    }
 }

void hoar_center_sort (int* a, const size_t n) {
    Hoar_center_sort (a, 0, n-1);
}