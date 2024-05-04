#ifndef COUNTING_SORTINGS_H
#define COUNTING_SORTINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
 * Сортирует массив целых чисел методом LSD (Least Significant Digit).
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n * k), где k - количество бит в числе.
 */
void lsd_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом MSD (Most Significant Digit).
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n * k), где k - количество бит в числе.
 */
void msd_sort(int* a, const size_t n);

#endif //COUNTING_SORTINGS_H
