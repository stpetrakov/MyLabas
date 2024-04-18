 #include "quick_sortings.h"
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))


int choose_pivot_median3random(int* a , int left, int right) {
    srand(time(NULL));

    int rand1 = left + rand() % (right - left + 1);
    int rand2 = left + rand() % (right - left + 1);
    int rand3 = left + rand() % (right - left + 1);
    int median = max(min(a[rand1], a[rand2]), min(max(a[rand1], a[rand2]), a[rand3]));

    if (median == a[rand1])
        return a[rand1];

    else if (median == a[rand2])
        return a[rand2];

    else
        return a[rand3];
}
 
int hoar_median3random_partition (int* a, int low, int high) {
    int pivot = choose_pivot_median3random (a, low, high);
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


 void Hoar_median3random_sort (int* a, int low, int high) {
    if (low < high) {
        int p = hoar_median3random_partition (a, low, high);

        Hoar_median3random_sort (a, low, p);
        Hoar_median3random_sort (a, p + 1, high);
    }
 }

void hoar_median3random_sort (int* a, const size_t n) {
    Hoar_median3random_sort (a, 0, n-1);
}