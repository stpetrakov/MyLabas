#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void quick_sort (int *a, int n) {
    assert (a != NULL);

    int x = 0;
    int y = n - 1;
    int med = a[n/2];

    while (x <= y) {
        while (a[x] < med)
            x++;

        while (a[y] > med)
            y--;

        if (x <= y) {
            int t = a[x];
            a[x] = a[y];
            a[y] = t;
            x++;
            y--;
        }
    }

    if (y > 0)
        quick_sort (a, y + 1);

    if (x < n)
        quick_sort (a + x, n - x);

}

int main () {
    int n;
    scanf("%d", &n);
    int *a;
    a = (int*) malloc(n*sizeof(int));

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
