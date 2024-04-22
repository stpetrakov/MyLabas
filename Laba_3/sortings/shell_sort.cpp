#include "square_sortings.h"

void shell_sort(int* a, const size_t n) {
    size_t step = 1;

    while (step <= n / 9)
        step = step * 3 + 1;

    for (; step > 0; step /= 3) {
        for (size_t i = 0; i < n; i += step) {
            size_t j = i;
            int t = a[i];

            for (; j >= step && a[j - step] > t; j -= step)
                a[j] = a[j - step];

            a[j] = t;
        }
    }
}