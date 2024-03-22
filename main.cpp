#include "tests/tests_generator.h"
#include "tests/testing.h"
#include "sortings/all_sortings.h"
using SortFunction = void (*)(int *, int);

int main() {
    // Пути к тестовым данным и результатам
    const char* test_dir = "tests/small_tests";
    const char* output_dir = "tests/small_tests";
    const char* function_name = "shell_sort";

    // Диапазон размеров тестов
    int from = 0;
    int to = 1000;
    int step = 50;

    SortFunction sort_function = &shell_sort;
    // Вызов функции тестирования
    test_sorting (test_dir, sort_function, function_name, output_dir, from, to, step);
    

    return 0;
}
