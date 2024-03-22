 #include "all_sortings.h"
 
int lomuto_partition (int* a, int low, int high) {
    int pivot = a[low + (high - low) / 2];

    int temp = a[low + (high - low) / 2];
    a[low + (high - low) / 2] = a[high];
    a[high] = temp;

    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;   
        }
    }

    temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;

    return i + 1;
}

 void my_lomuto_sort (int* a, int low, int high) {
    if (low < high) {
        int p = lomuto_partition (a, low, high);

        my_lomuto_sort (a, low, p - 1);
        my_lomuto_sort (a, p + 1, high);
    }
 }

void lomuto_sort (int* a, int n) {
    my_lomuto_sort (a, 0, n-1);
}