 #include "quick_sortings.h"

int choose_pivot_random (int* a, int left, int right) {
    srand(time(NULL));
    return a[left + rand() % (right - left)];
}
 
int hoar_random_partition (int* a, int low, int high) {
    int pivot = choose_pivot_random (a, low, high);
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


 void Hoar_random_sort (int* a, int low, int high) {
    if (low < high) {
        int p = hoar_random_partition (a, low, high);

        Hoar_random_sort (a, low, p);
        Hoar_random_sort (a, p + 1, high);
    }
 }

void hoar_random_sort (int* a, const size_t n) {
    Hoar_random_sort (a, 0, n-1);
}