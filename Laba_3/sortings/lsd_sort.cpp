#include "counting_sortings.h"

#define MAX_NUM_DIGITS 32 // Максимальное количество разрядов в числе
#define RADIX 256 // Основание системы счисления
#define BIT_SIZE 8 // Размер бита

void lsd_sort (int* a, const size_t n) {
    int* output = (int*) calloc (n, sizeof(int)); 
    assert (output != NULL);

    int* count = (int*) calloc (RADIX, sizeof(int)); 
    assert (count != NULL);

    for (size_t exp = 1; exp <= MAX_NUM_DIGITS; exp++) {
        for (size_t i = 0; i < RADIX; i++)
            count[i] = 0;

        for (size_t i = 0; i < n; i++)
            count[(a[i] >> (BIT_SIZE * (exp - 1))) & (RADIX - 1)]++;

        for (size_t i = 1; i < RADIX; i++)
            count[i] += count[i - 1];

        for (size_t i = n - 1; i >= 0; i--) {
            output[count[(a[i] >> (BIT_SIZE * (exp - 1))) & (RADIX - 1)] - 1] = a[i];
            count[(a[i] >> (BIT_SIZE * (exp - 1))) & (RADIX - 1)]--;
        }

        memcpy(a, output, n * sizeof(int));
    }

    free (output);
    free (count);
}