 #include "quick_sortings.h"
 
int lomuto_partition (int* a, int low, int high) {
    int pivot = a[low + (high - low) / 2];

    int temp = a[low + (high - low) / 2];
    a[low + (high - low) / 2] = a[high];
    a[high] = temp;

    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap (&a[i], &a[j], int);  
        }
    }

    swap (&a[i + 1], &a[high], int);

    return i + 1;
}

 void Lomuto_sort (int* a, int low, int high) {
    if (low < high) {
        int p = lomuto_partition (a, low, high);

        Lomuto_sort (a, low, p - 1);
        Lomuto_sort (a, p + 1, high);
    }
 }

void lomuto_sort (int* a, const size_t n) {
    Lomuto_sort (a, 0, n-1);
}