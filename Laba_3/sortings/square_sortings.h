#ifndef SQUARE_SORTINGS_H
#define SQUARE_SORTINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define swap(x, y, T) do { T temp = *x; *x = *y; *y = temp; } while (0)

/**
 * Сортирует массив целых чисел методом пузырьковой сортировки.
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void bubble_sort(int *a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки вставками.
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void insertion_sort(int *a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки выбором.
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void selection_sort(int *a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Шелла.
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void shell_sort(int *a, const size_t n);


#endif // SQUARE_SORTINGS_H
