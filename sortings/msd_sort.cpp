#include "all_sortings.h"

#define BYTE_SIZE 256

int msd (int num, int byte_num) {
    return (num >> (8 * byte_num)) & 0xFF;
}

void my_msd_sort (int* a, int left, int right, int byte_num) {
    if (left >= right || byte_num < 0) 
        return;

    int count[BYTE_SIZE] = {0};

    for (int i = left; i <= right; i++) {
        count[msd(a[i], byte_num)]++;
    }

    int index[BYTE_SIZE] = {0};

    for (int i = 1; i < BYTE_SIZE; i++)
        index[i] = index[i - 1] + count[i - 1];

    int* temp = (int*) calloc (right - left + 1, sizeof(int));

    for (int i = left; i <= right; i++)
        temp[index[msd (a[i], byte_num)]++] = a[i];

    for (int i = left; i <= right; i++)
        a[i] = temp[i - left];

    free(temp);

    for (int i = 0; i < BYTE_SIZE; i++)
        my_msd_sort(a, left + index[i - 1], left + index[i] - 1, byte_num - 1);
}

void msd_sort(int* a, int size) {
    my_msd_sort (a, 0, size - 1, sizeof(int) - 1);
}
