#ifndef SQUARE_SORTINGS_H
#define SQUARE_SORTINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
 * Сортирует массив целых чисел методом пузырьковой сортировки.
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n^2)
 */
void bubble_sort(int *a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки вставками.
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n^2)
 */
void insertion_sort(int *a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки выбором.
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n^2)
 */
void selection_sort(int *a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Шелла.
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - В среднем O(n^1.25)
 */
void shell_sort(int *a, const size_t n);

/**
 * Сортирует массив целых чисел методом оптимизированной рекурсивным бин поиском  сортировки вставками.
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - В худшем случае O(n^2), в лучшем - O(n)
 */
void optimized_insertion_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом оптимизированной итеративным бин поиском сортировки вставками.
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - В худшем случае O(n^2), в лучшем - O(n)
 */
void optimized_insertion2_sort(int* a, const size_t n);

#endif // SQUARE_SORTINGS_H
