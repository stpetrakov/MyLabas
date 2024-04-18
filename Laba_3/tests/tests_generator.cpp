#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <array_size> <max_value>\n", argv[0]);
        return 1;
    }

    int array_size = atoi (argv[1]);
    int max_value = atoi (argv[2]);

    assert (array_size > 0);
    assert (max_value > 0);

    srand(time(NULL));

    int* array = (int*) malloc(array_size * sizeof(int));
    assert (array != NULL);

    for (int i = 0; i < array_size; i++) {
        array[i] = rand() % (max_value + 1); 
    }

    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}