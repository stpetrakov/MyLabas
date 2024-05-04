#include "quick_sortings.h"
#define min(a, b) ((a) < (b) ? (a) : (b))


void iterative_merge(int* array, int left, int middle, int right, int* left_array, int* right_array) {
    int left_size = middle - left + 1;
    int right_size = right - middle;

    memcpy(left_array, &array[left], left_size * sizeof(int));
    memcpy(right_array, &array[middle + 1], right_size * sizeof(int));

    int left_index = 0;
    int right_index = 0;
    int merge_index = left;

    while (left_index < left_size && right_index < right_size) {
        if (left_array[left_index] <= right_array[right_index]) {
            array[merge_index] = left_array[left_index];
            left_index++;
        } else {
            array[merge_index] = right_array[right_index];
            right_index++;
        }
        merge_index++;
    }

    while (left_index < left_size) {
        array[merge_index] = left_array[left_index];
        left_index++;
        merge_index++;
    }

    while (right_index < right_size) {
        array[merge_index] = right_array[right_index];
        right_index++;
        merge_index++;
    }
}


void iterative_merge_sort(int* array, const size_t n) {
    int* temp_array = (int*)malloc(n * sizeof(int));
    assert(temp_array != NULL);

    for (size_t curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (size_t left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            size_t middle = min (left_start + curr_size - 1, n - 1);
            size_t right_end = min (left_start + 2 * curr_size - 1, n - 1);

            int* left_temp_array = (int*) malloc((middle - left_start + 1) * sizeof(int));
            int* right_temp_array = (int*) malloc((right_end - middle) * sizeof(int));
            assert (left_temp_array != NULL && right_temp_array != NULL);

            memcpy (left_temp_array, &array[left_start], (middle - left_start + 1) * sizeof(int));
            memcpy (right_temp_array, &array[middle + 1], (right_end - middle) * sizeof(int));

            iterative_merge (array, left_start, middle, right_end, left_temp_array, right_temp_array);

            free (left_temp_array);
            free (right_temp_array);
        }
    }

    free(temp_array);
}
