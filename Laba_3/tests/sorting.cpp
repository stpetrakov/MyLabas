#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int val_a = *(const int*)a;
    int val_b = *(const int*)b;
    
    return (val_a > val_b) - (val_a < val_b);
}

void wrire_array (int* a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main(int argc, char *argv[]) {
    assert (argc >= 2);
    size_t n = atoi(argv[1]);
    int* array = (int*) malloc(n*sizeof(int));
    assert (array != NULL);
    
    for (size_t i = 0; i < n; i++) {
        assert (scanf("%d", &array[i]) == 1);
    }

    qsort(array, n, sizeof(int), cmp);

    wrire_array (array, n);
    
    free(array);
    return 0;
}
