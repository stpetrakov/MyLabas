#ifndef QUICK_SORTINGS_H
#define QUICK_SORTINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>


/**
 * Сортирует массив целых чисел методом сортировки кучей (heapsort).
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @param k - Количество детей.
 * @complexity - O(n*log(n))
 */
void heap_sort(int* a, size_t n, int k);

/**
 * Сортирует массив целых чисел методом рекурсивной сортировки слиянием (merge sort).
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n*log(n))
 */
void recursive_merge_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом итеративной сортировки слиянием (merge sort).
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n*log(n))
 */
void iterative_merge_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Ломуто.
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n*log(n))
 */
void lomuto_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Хоара (quicksort).
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n*log(n))
 */
void hoar_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом "толстой" сортировки.
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n*log(n))
 */
void thick_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Хоара (quicksort) и выбора в качестве pivot центрального элемента.
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n*log(n))
 */
void hoar_center_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Хоара (quicksort) и выбора в качестве pivot медианы 3.
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n*log(n))
 */
void hoar_median3_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Хоара (quicksort) и выбора в качестве pivot случайного элемента.
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n*log(n))
 */
void hoar_random_sort(int* a, const size_t n);

/**
 * Сортирует массив целых чисел методом сортировки Хоара (quicksort) и выбора в качестве pivot медианы случайных 3 элементов.
 *
 * @param a - Указатель на массив для сортировки.
 * @param n - Размер массива.
 * @complexity - O(n*log(n))
 */
void hoar_median3random_sort(int* a, const size_t n);

//просто партишион
int hoar_partition (int* a, int low, int high, int pivot);

#endif // QUICK_SORTINGS_H

