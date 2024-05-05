#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void wrire_array (int* a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void fill_rand_array (int* array, size_t array_size, int max_value) {
    for (size_t i = 0; i < array_size; i++) {
        array[i] = rand() % (max_value + 1); 
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <array_size> <max_value>\n", argv[0]);
        return 1;
    }

    size_t array_size = atoi (argv[1]);
    int max_value = atoi (argv[2]);

    assert (array_size > 0);
    assert (max_value > 0);

    srand(time(NULL));

    int* array = (int*) malloc(array_size * sizeof(int));
    assert (array != NULL);

    fill_rand_array (array, array_size, max_value);
    wrire_array (array, array_size);

    free(array);
    return 0;
}