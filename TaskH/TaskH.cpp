#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort (int *a, int n) {
    assert (a != NULL);

    int i = 0;
    int j = n - 1;
    int med = a[n/2];

    while (i <= j) {
        while (a[i] < med)
            i++;

        while (a[j] > med)
            j--;

        if (i <= j) {
            swap (&a[i], &a[j]);
            i++;
            j--;
        }
    }

    if (j > 0)
        quick_sort (a, j + 1);

    if (i < n)
        quick_sort (a + i, n - i);

}

int main () {
    int n;
    scanf("%d", &n);

    int *a;
    a = (int*) malloc(n*sizeof(int));
    assert(a != NULL);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }

    quick_sort (a, n);

    for (int i = 0; i < n; i++)
        printf ("%d ", a[i]);

    free (a);

    return 0;
}
