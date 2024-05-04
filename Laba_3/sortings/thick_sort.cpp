 #include "quick_sortings.h"
 #include "swap.h"
 
int thick_partition (int* a, int low, int high) {
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

        swap (a[i], a[j]);
    }
}



 void Thick_sort(int* a, int low, int high) {
    if (low < high) {
        int p = thick_partition (a, low, high);

        Thick_sort(a, low, p);
        Thick_sort(a, p + 1, high);
    }
 }

void thick_sort (int* a, const size_t n) {
    Thick_sort (a, 0, n - 1);
}