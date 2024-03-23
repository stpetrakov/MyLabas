 #include "all_sortings.h"
 
int hoar_partition (int* a, int low, int high) {
    int pivot = a[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i >= j)
            return j;

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}


 void my_hoar_sort (int* a, int low, int high) {
    if (low < high) {
        int p = hoar_partition (a, low, high);

        my_hoar_sort (a, low, p);
        my_hoar_sort (a, p + 1, high);
    }
 }

void hoar_sort (int* a, int n) {
    my_hoar_sort (a, 0, n-1);
}