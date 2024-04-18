 #include "quick_sortings.h"

 int choose_pivot_center (int* a, int left, int right) {
    return a[right + (left - right) / 2];
}
 
int hoar_center_partition (int* a, int low, int high) {
    int pivot = choose_pivot_center (a, low, high);
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


 void Hoar_center_sort (int* a, int low, int high) {
    if (low < high) {
        int p = hoar_center_partition (a, low, high);

        Hoar_center_sort (a, low, p);
        Hoar_center_sort (a, p + 1, high);
    }
 }

void hoar_center_sort (int* a, const size_t n) {
    Hoar_center_sort (a, 0, n-1);
}