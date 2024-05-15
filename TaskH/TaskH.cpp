#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

void swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort (int *a, int n) {
    assert (a != NULL);

    int i = 0;
    int j = n - 1;
    int med = a[i + rand() % (j - i)];

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

	if (i < n - 1)
    	quick_sort (a + i, n - i);

}

int main () {
    int n;

    if (scanf("%d", &n) != 1) {
        printf ("ERROR: scanf != 1");
        return 0;
    }

    int *a;
    a = (int*) malloc(n*sizeof(int));
    assert(a != NULL);

    for (int i = 0; i < n; i++) {
        int x;

        if (scanf("%d", &x) != 1) {
            printf ("ERROR: scanf != 1");
            return 0;
        }

        a[i] = x;
    }

    quick_sort (a, n);

    for (int i = 0; i < n; i++)
        printf ("%d ", a[i]);

    free (a);

    return 0;
}
