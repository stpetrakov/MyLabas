 #include "quick_sortings.h"

int choose_pivot_median3 (int* arr, int left, int right) {
    int mid = (left + right) / 2;

    if (arr[left] > arr[mid])
        swap(&arr[left], &arr[mid], int);

    if (arr[left] > arr[right])
        swap(&arr[left], &arr[right], int);

    if (arr[mid] > arr[right])
        swap (&arr[mid], &arr[right], int);

    return mid;
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

        swap (&a[i], &a[j], int);
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