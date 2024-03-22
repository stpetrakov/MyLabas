#include "testing.h"
#include "C:\Github\Third_Laba\sortings\all_sortings.h"

int compare_arrays (const int *a, const int *b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return arrays_not_equal; 
        }
    }
    return arrays_equal; 
}

void read_array_from_file (const char *filename, int *array, int size) {
    FILE *file = fopen (filename, "r");
    assert (file != NULL);

    for (int i = 0; i < size; i++) {
        if (fscanf (file, "%d", &array[i]) != 1) {
            fprintf (stderr, "Error: Unable to read array from file %s\n", filename);
            exit (EXIT_FAILURE);
        }
    }

    fclose (file);
}

void record_results (const double ans, const char* function_name) {
    FILE *answer;
    char way[200];
    sprintf (way, "C:/Github/Third_Laba/tests/answers/%s.txt", function_name);

    answer = fopen(way, "a+");
    assert (answer != NULL);

    fprintf (answer, "%lg ", ans);

    fclose (answer);
}

void test_sorting (const char* test_dir, void (*sort_function)(int* , int), const char* function_name, const char* output_dir, int from, int to, int step) {
    clock_t start, end;
    int test_index = 0;
    for (int size = from; size <= to; size += step) {
        double ans = 0;
        for (int i = 1; i <= 5; i++) {
            char input_filename[20];
            sprintf (input_filename, "%s/%d_%d.in", test_dir, size, i);

            int *array = (int*) calloc (size, sizeof(int));
            assert (array != NULL);

            read_array_from_file (input_filename, array, size);

            start = clock();
            sort_function (array, size);
            end = clock();
            ans += ((double) (end - start)) / CLOCKS_PER_SEC;

            char output_filename[100];
            sprintf (output_filename, "%s/%d_%d.out", output_dir, size, i);

            int* expected_result = (int*) calloc (size, sizeof(int));
            assert (expected_result != NULL);
             
            read_array_from_file (output_filename, expected_result, size);

            if (!compare_arrays(array, expected_result, size)) {
                fprintf(stderr, "Error: Sorting function failed on test %d\n", size / step);
                exit(EXIT_FAILURE);
            }

            free (array);
            free (expected_result);
        }
        record_results (ans, function_name);
        test_index++;
        printf ("%d\n", test_index);

    }
}

void test_heap(const char* test_dir, const char* function_name, const char* output_dir, int from, int to, int step) {

    clock_t start, end;
    int test_index = 0;
    for (int q = 2; q < 10; q++) {
        for (int size = from; size <= to; size += step) {
            double ans = 0;
            for (int i = 1; i <= 5; i++) {
                char input_filename[20];
                sprintf (input_filename, "%s/%d_%d.in", test_dir, size, i);

                int *array = (int*) malloc(size * sizeof(int));
                assert (array != NULL);

                read_array_from_file (input_filename, array, size);

                start = clock();
                heap_sort (array, size, q);
                end = clock();
                ans += ((double) (end - start)) / CLOCKS_PER_SEC;

                char output_filename[100];
                sprintf (output_filename, "%s/%d_%d.out", output_dir, size, i);

                int* expected_result = (int*) malloc(size * sizeof(int));
                assert (expected_result != NULL);
                
                read_array_from_file (output_filename, expected_result, size);

                if (!compare_arrays (array, expected_result, size)) {
                    fprintf (stderr, "Error: Sorting function failed on test %d\n", size / step);
                    exit (EXIT_FAILURE);
                }

                free (array);
                free (expected_result);

                //printf("%lg ", execution_times[test_index]);
            }
            test_index++;
            char new_function_name[100];
            sprintf (new_function_name, "%s_for_%d", function_name, q);
            record_results (ans, new_function_name);
            printf("%d\n", test_index);
        }
    }
}
