#include "tests.h"
#include "../Heaps/binary_heap.h"

void read_array_from_file (const char *filename, int *array, int size) {
    FILE *file = fopen (filename, "r");
    assert (file != NULL);

    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d", &array[i]) != 1) {
            fprintf(stderr, "ERROR: reading file\n");
            
            exit(EXIT_FAILURE);
        }
    }

    fclose (file);
}

double test(int type) {

    char answer[_MAX_FNAME];

    if (type)
        sprintf(answer, "linear.txt");

    else
        sprintf(answer, "normal.txt");

    FILE* ans_file = fopen(answer, "w");
    assert (ans_file); 


    for (int size = STEP; size <= MAX_SIZE; size += STEP) {
        int *array = (int*) malloc(size * sizeof(int));
        assert (array != NULL);

        char filename[_MAX_FNAME];
        sprintf(filename, "Tests/Arrays/%d.txt", size);

        printf ("%s ", filename);

        read_array_from_file (filename, array, size);

        clock_t start = clock();

        if (type)
            line_heap (array, size);

        else
            norm_heap (array, size);

        clock_t end = clock();

        double ans = ((double) (end - start)) / CLOCKS_PER_SEC;

        fprintf(ans_file, "%lg ", ans);
        printf ("%lg\n", ans);

        free (array);
    }

    fclose(ans_file);
}