#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    //scanf("%d", &n);
    int* array = (int*) malloc(n*sizeof(int));

    //printf("%d\n", n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    qsort(array, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    
    free(array);
    return 0;
}
