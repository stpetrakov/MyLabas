#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct Binary_heap {
    int *data_min; //отвечает за минимум
    int *data_max;  //отвечает за максимум
    int size;
    int capacity;
};


void swap (int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

struct Binary_heap* init (int capacity) {
    struct Binary_heap* heap;
    heap = (struct Binary_heap*) calloc(1, sizeof(struct Binary_heap));
    assert (heap);

    heap->data_min = (int*) calloc (capacity, sizeof(int));
    heap->data_max = (int*) calloc (capacity, sizeof(int));
    heap->capacity = capacity;

    assert (heap->data_min);
    assert (heap->data_max);

    heap->size = 0;

    return heap;
}

void sift_up_min (struct Binary_heap *heap, int i) {
    assert (heap);

    while (i != 0) {
        if (heap->data_min[(i - 1)/2] > heap->data_min[i]) {
            swap (&heap->data_min[i], &heap->data_min[(i - 1)/2]);
            i = (i - 1)/2;
        }

        else
            break;
    }
}

void sift_up_max (struct Binary_heap *heap, int i) {
    assert (heap);

    while (i != 0) {
        if (heap->data_max[(i - 1)/2] < heap->data_max[i]) {
            swap (&heap->data_max[i], &heap->data_max[(i - 1)/2]);
            i = (i - 1)/2;
        }

        else
            break;
    }
}

void sift_down_min (struct Binary_heap *heap, int i) {
    assert (heap);

    while (2*i + 1 < heap->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = i;


        if (left < heap->size && heap->data_min[left] < heap->data_min[j]) {
            j = left;
        }

        if (right < heap->size && heap->data_min[right] < heap->data_min[j]) {
            j = right;
        }

        if (j == i) {
            break;
        }

        else {
            swap (&heap->data_min[i], &heap->data_min[j]);
            i = j;
        }
    }
}

void sift_down_max (struct Binary_heap *heap, int i) {
    assert (heap);

    while (2*i + 1 < heap->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = i;

        if (left < heap->size && heap->data_max[left] > heap->data_max[j]) {
            j = left;
        }

        if (right < heap->size && heap->data_max[right] > heap->data_max[j]) {
            j = right;
        }


        if (j == i) {
            break;
        }

        else {
            swap (&heap->data_max[i], &heap->data_max[j]);
            i = j;
        }
    }
}

void insert (struct Binary_heap *heap, int n) {
    assert (heap);
    assert (heap->data_min);

    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data_min = (int*) realloc(heap->data_min, heap->capacity * sizeof(int));
        heap->data_max = (int*) realloc(heap->data_max, heap->capacity * sizeof(int));
    }

    heap->data_min[heap->size] = n;
    heap->data_max[heap->size] = n;
    heap->size++;

    sift_up_min(heap, heap->size - 1);
    sift_up_max(heap, heap->size - 1);

    printf("ok\n");
}

void extract_min (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data_min);

    if (heap->size == 0)
        printf ("error\n");

    else {
        heap->size--;
        int mi = heap->data_min[0];
        heap->data_min[0] = heap->data_min[heap->size];

        for (int i = heap->size/2; i <= heap->size; i++) {
            if (heap->data_max[i] == mi) {
                heap->data_max[i] = heap->data_max[heap->size];
                sift_up_max (heap, i);
                break;
            }
        }

   		sift_down_min (heap, 0);

        printf("%d\n", mi);
    }
}

void get_min (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data_min);

    if (heap->size == 0)
        printf ("error\n");

    else
        printf ("%d\n", heap->data_min[0]);
}

void extract_max (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data_max);

    if (heap->size == 0)
        printf ("error\n");

    else {
        heap->size--;
        int ma = heap->data_max[0];
        heap->data_max[0] = heap->data_max[heap->size];

        for (int i = heap->size/2; i < heap->size; i++) {
            if (heap->data_min[i] == ma) {
                heap->data_min[i] = heap->data_min[heap->size];
                sift_up_min(heap, i);
                break;
            }
        }
    	sift_down_max(heap, 0);

        printf("%d\n", ma);
    }
}

void get_max (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data_max);

    if (heap->size == 0)
        printf ("error\n");

    else
        printf ("%d\n", heap->data_max[0]);
}

void size (struct Binary_heap *heap) {
    assert (heap);

    printf ("%d\n", heap->size);
}

void clear (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data_max);
    assert (heap->data_min);

    heap->size = 0;
    printf("ok\n");

}

int main() {
    struct Binary_heap* heap;
    heap = init(1);
    char a[20];

    int n;
    scanf ("%d", &n);

    while (n) {
        scanf("%s", a);

        if (a[0] == 'i') {
            int t;
            scanf("%d", &t);
            insert (heap, t);
        }
        else if (a[0] == 'e' && a[9] == 'i')
        {
            extract_min (heap);
        }
        else if (a[0] == 'g' && a[5] == 'i')
        {
            get_min (heap);
        }
        else if (a[0] == 'e' && a[9] == 'a')
        {
            extract_max (heap);
        }
        else if (a[0] == 'g' && a[5] == 'a')
        {
            get_max (heap);
        }
        else if (a[0] == 's')
        {
            size (heap);
        }
        else if (a[0] == 'c')
        {
            clear (heap);
        }

        n--;
    }
    return 0;
}


