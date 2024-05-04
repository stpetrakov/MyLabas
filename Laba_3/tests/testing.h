#ifndef TESTING_H
#define TESTING_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


enum status {
    ARRAYS_NOT_EQUAL = 0,
    ARRAYS_EQUAL = 1
};

/**
 * Тестирует сортировку для заданных тестов.
 *
 * @param test_dir Директория с тестовыми данными.
 * @param sort_function Указатель на функцию сортировки.
 * @param function_name Название функции сортировки.
 * @param output_dir Директория для записи результатов.
 * @param from Начальное значение числа тестов.
 * @param to Конечное значение числа тестов.
 * @param step Шаг изменения числа тестов.
 */
void test_sorting(const char *test_dir, void (*sort_function)(int *, size_t), const char *function_name,
                  const char *output_dir, int from, int to, int step);

/**
 * Тестирует кучу для заданных тестов.
 *
 * @param test_dir Директория с тестовыми данными.
 * @param function_name Название функции кучи.
 * @param output_dir Директория для записи результатов.
 * @param from Начальное значение числа тестов.
 * @param to Конечное значение числа тестов.
 * @param step Шаг изменения числа тестов.
 */
void test_heap(const char *test_dir, const char *function_name, const char *output_dir, int from, int to, int step);

#endif // TESTING_H
