#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return ((*(int*)a / 2 ) - (*(int*)b / 2));
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int* array = (int*) malloc(n*sizeof(int));
    assert (array != NULL);
    
    for (int i = 0; i < n; i++) {
        assert (scanf("%d", &array[i]) == 1);
    }

    qsort(array, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    
    free(array);
    return 0;
}
