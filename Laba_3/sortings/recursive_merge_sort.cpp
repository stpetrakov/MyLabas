#include "quick_sortings.h"

void recursive_merge(int* array, int left, int middle, int right) {
    int size_left = middle - left + 1;
    int size_right = right - middle;

    int* left_array = (int*) calloc(size_left, sizeof(int)); 
    assert (left_array != NULL);

    int* right_array = (int*) calloc(size_right, sizeof(int)); 
    assert (right_array != NULL);

    for (size_t index_left = 0; index_left < size_left; index_left++)
        left_array[index_left] = array[left + index_left];

    for (size_t index_right = 0; index_right < size_right; index_right++)
        right_array[index_right] = array[middle + 1 + index_right];

    int index_left = 0; 
    int index_right = 0;
    int index_merged = left; 

    while (index_left < size_left || index_right < size_right) {
        if (index_left < size_left && (index_right >= size_right || left_array[index_left] <= right_array[index_right])) {
            array[index_merged] = left_array[index_left];
            index_left++;
        } 

        else {
            array[index_merged] = right_array[index_right];
            index_right++;
        }

        index_merged++;
    }

    free(left_array);
    free(right_array);
}


void Recursive_merge_sort(int* a, size_t l, size_t r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        Recursive_merge_sort(a, l, m);
        Recursive_merge_sort(a, m + 1, r);

        recursive_merge(a, l, m, r);
    }
}

void recursive_merge_sort(int* a, const size_t n) {
    Recursive_merge_sort (a, 0, n - 1);
}