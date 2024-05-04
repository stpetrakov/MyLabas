#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 1000000
#define STEP 100000

int main() {
    srand (42);

    for (int k = 1; k <= 10; k++) {
        char filename[_MAX_FNAME];
        sprintf(filename, "Arrays/%d.txt", k * STEP);
        FILE* file = fopen(filename, "w");

        assert (file); 

        for (int i = 0; i < STEP * k; i++) {
            fprintf(file, "%d ", rand() % MAX_SIZE + 1);
        }

        fclose(file);
    }

    return 0;
}
