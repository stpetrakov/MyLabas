#ifndef COUNTING_SORTINGS_H
#define COUNTING_SORTINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define swap(x, y, T) do { T temp = *x; *x = *y; *y = temp; } while (0)

/**
 * Сортирует массив целых чисел методом LSD (Least Significant Digit).
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void lsd_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом MSD (Most Significant Digit).
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void msd_sort(int* a, const size_t n);


#endif //COUNTING_SORTINGS_H