#include "quick_sortings.h"
#include "swap.h"

int choose_pivot_random (int* a, int left, int right) {
    srand(time(NULL));
    return a[left + rand() % (right - left)];
}

void Hoar_random_sort (int* a, int low, int high) {
    if (low < high) {
        int p = hoar_partition (a, low, high, choose_pivot_random (a, low, high));

        Hoar_random_sort (a, low, p);
        Hoar_random_sort (a, p + 1, high);
    }
 }

void hoar_random_sort (int* a, const size_t n) {
    Hoar_random_sort (a, 0, n-1);
}