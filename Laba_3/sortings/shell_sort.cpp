#include "all_sortings.h"

void shell_sort(int* a, int n) {
    int step = 1;

    while (step <= n / 9)
        step = step * 3 + 1;

    for (; step > 0; step /= 3) {
        for (int i = 0; i < n; i += step) {
            int j = i;
            int t = a[i];

            for (; j >= step && a[j - step] > t; j -= step)
                a[j] = a[j - step];

            a[j] = t;
        }
    }
}