#ifndef TESTING_H
#define TESTING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

enum status {
    arrays_not_equal = 0,
    arrays_equal = 1
};

/**
 * Сравнивает два массива целых чисел.
 *
 * @param a Указатель на первый массив.
 * @param b Указатель на второй массив.
 * @param size Размер массивов.
 * @return Результат сравнения:
 *         < 0, если a < b
 *         0, если a == b
 *         > 0, если a > b
 */
int compare_arrays(const int *a, const int *b, int size);

/**
 * Считывает массив из файла.
 *
 * @param filename Имя файла для чтения.
 * @param array Указатель на массив, в который будет записан результат.
 * @param size Размер массива.
 */
void read_array_from_file(const char *filename, int *array, int size);

/**
 * Записывает результаты исполнения в файл.
 *
 * @param execution_times Массив времен выполнения.
 * @param ans Результат тестирования.
 * @param num_tests Количество тестов.
 */
void record_results(const double *execution_times, const char *ans, const int num_tests);

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
