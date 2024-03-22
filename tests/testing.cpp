#include "testing.h"
#include "C:\Github\Third_Laba\sortings\all_sortings.h"

// Функция для сравнения двух массивов целых чисел
int compare_arrays(const int *a, const int *b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return 0; // Массивы не равны
        }
    }
    return 1; // Массивы равны
}

// Функция для чтения массива из файла
void read_array_from_file(const char *filename, int *array, int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d", &array[i]) != 1) {
            fprintf(stderr, "Error: Unable to read array from file %s\n", filename);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

void record_results (const double* execution_times, const char* function_name, const int num_tests) {
    FILE *answer;
    char way[200];
    sprintf(way, "C:/Github/Third_Laba/tests/answers/%s.txt", function_name);

    answer = fopen(way, "a+");
    if (answer == NULL) {
        perror("Ошибка при открытии файла");
        return;
    }
    for (int i = 0; i < num_tests; i++) {
        fprintf(answer, "%lg ", execution_times[i]);
    }
    fclose(answer);
}

// Функция для тестирования сортировки
void test_sorting(const char* test_dir, void (*sort_function)(int* , int), const char* function_name, const char* output_dir, int from, int to, int step) {
    int num_tests = (to - from) / step + 1;
    double *execution_times = (double *) calloc(num_tests, sizeof(double));
    if (execution_times == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    clock_t start, end;
    int test_index = 0;
    for (int size = from; size <= to; size += step) {
        for (int i = 1; i <= 5; i++) {
            // Формирование имени входного файла
            char input_filename[20];
            sprintf(input_filename, "%s/%d_%d.in", test_dir, size, i);

            // Чтение массива из входного файла
            int *array = (int *)malloc(size * sizeof(int));
            if (array == NULL) {
                fprintf(stderr, "Error: Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            read_array_from_file(input_filename, array, size);

            // Замер времени выполнения сортировки
            start = clock();
            sort_function(array, size);
            end = clock();
            execution_times[test_index] += ((double) (end - start)) / CLOCKS_PER_SEC;

            // Формирование имени выходного файла
            char output_filename[100];
            sprintf(output_filename, "%s/%d_%d.out", output_dir, size, i);

            // Чтение ожидаемого результата из выходного файла
            int *expected_result = (int *)malloc(size * sizeof(int));
            if (expected_result == NULL) {
                fprintf(stderr, "Error: Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            read_array_from_file(output_filename, expected_result, size);

            // Проверка, что полученный результат совпадает с ожидаемым
            if (!compare_arrays(array, expected_result, size)) {
                fprintf(stderr, "Error: Sorting function failed on test %d\n", size);
                exit(EXIT_FAILURE);
            }

            // Освобождение памяти
            free(array);
            free(expected_result);

            //printf("%lg ", execution_times[test_index]);
        }
        test_index++;
    }

    record_results (execution_times, function_name, num_tests);
}
