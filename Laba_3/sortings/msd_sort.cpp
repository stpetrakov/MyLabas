#include "counting_sortings.h"

#define MAX_DIGIT_VALUE 256
#define BYTE_SIZE 8

int get_byte (int num, int byte_num) {
    return (num >> (BYTE_SIZE * byte_num)) & 0xFF;
}

void Msd_sort (int* a, int left, int right, int byte_num) {
    if (left >= right || byte_num < 0) 
        return;

    int count[MAX_DIGIT_VALUE] = {0};

    for (size_t i = left; i <= right; i++) {
        count[get_byte(a[i], byte_num)]++;
    }

    int index[MAX_DIGIT_VALUE] = {0};

    for (size_t i = 1; i < MAX_DIGIT_VALUE; i++)
        index[i] = index[i - 1] + count[i - 1];

    int* temp = (int*) calloc (right - left + 1, sizeof(int));
    assert (temp != NULL);

    for (size_t i = left; i <= right; i++)
        temp[index[get_byte (a[i], byte_num)]++] = a[i];

    memcpy(&a[left], temp, (right - left + 1) * sizeof(int));

    free(temp);

    for (size_t i = 0; i < MAX_DIGIT_VALUE; i++)
        Msd_sort(a, left + index[i - 1], left + index[i] - 1, byte_num - 1);
}

void msd_sort(int* a, const size_t size) {
    Msd_sort (a, 0, size - 1, sizeof(int) - 1);
}
