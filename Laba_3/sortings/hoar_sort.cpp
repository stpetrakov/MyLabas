 #include "quick_sortings.h"
 
int hoar_partition (int* a, int low, int high) {
    int pivot = a[low + (high - low) / 2];
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

        swap (&a[i], &a[j], int);
    }
}


 void Hoar_sort (int* a, int low, int high) {
    if (low < high) {
        int p = hoar_partition (a, low, high);

        Hoar_sort (a, low, p);
        Hoar_sort (a, p + 1, high);
    }
 }

void hoar_sort (int* a, const size_t n) {
    Hoar_sort (a, 0, n-1);
}