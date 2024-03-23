 #include "all_sortings.h"
 
int thick_partition (int* a, int low, int high) {
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



 void my_thick_sort(int* a, int low, int high) {
    if (low < high) {
        int p = thick_partition (a, low, high);

        my_thick_sort(a, low, p);
        my_thick_sort(a, p + 1, high);
    }
 }

void thick_sort (int* a, int n) {
    my_thick_sort (a, 0, n-1);
}