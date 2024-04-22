#ifndef QUICK_SORTINGS_H
#define QUICK_SORTINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#define swap(x, y, T) do { T temp = *x; *x = *y; *y = temp; } while (0)

/**
 * Сортирует массив целых чисел методом сортировки кучей (heapsort).
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 * @param k Количество детей.
 */
void heap_sort(int* a, const int n, int k);

/**
 * Сортирует массив целых чисел методом рекурсивной сортировки слиянием (merge sort).
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void recursive_merge_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом итеративной сортировки слиянием (merge sort).
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void iterative_merge_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Ломуто.
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void lomuto_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Хоара (quicksort).
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void hoar_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом "толстой" сортировки.
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void thick_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Хоара (quicksort) и выбора в качестве pivot центрального элемента.
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void hoar_center_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Хоара (quicksort) и выбора в качестве pivot медианы 3.
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void hoar_median3_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Хоара (quicksort) и выбора в качестве pivot случайного элемента.
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void hoar_random_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Хоара (quicksort) и выбора в качестве pivot медианы случайных 3 элементов.
 *
 * @param a Указатель на массив для сортировки.
 * @param n Размер массива.
 */
void hoar_median3random_sort(int* a, const size_t n);

#endif // QUICK_SORTINGS_H
