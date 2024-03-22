#include "all_sortings.h"

struct Binary_heap {
    int* data;
    int* arr;
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

    heap->data = (int*) calloc (capacity, sizeof(int));
    heap->arr = (int*) calloc (capacity, sizeof(int));
    heap->capacity = capacity;

    assert (heap->data);

    heap->size = 0;

    return heap;
}

void sift_up (struct Binary_heap *heap, int i) {
    assert (heap);

    while (heap->data[(i - 1)/2] > heap->data[i]) {
        swap (&heap->data[i], &heap->data[(i - 1)/2]);
        swap (&heap->arr[i], &heap->arr[(i - 1)/2]);

        i = (i - 1)/2;
    }
}

void sift_down (struct Binary_heap *heap, int i) {
    assert (heap);

    while (2*i + 1 < heap->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;

        if (right < heap->size && heap->data[right] < heap->data[left]) {
            j = right;
        }

        if (heap->data[i] <= heap->data[j]) {
            break;
        }

        swap (&heap->data[i], &heap->data[j]);
        swap (&heap->arr[i], &heap->arr[j]);
        i = j;
    }
}

void insert (struct Binary_heap *heap, int n, int q) {
    assert (heap);
    assert (heap->data);
	assert (heap->arr);

    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int*) realloc(heap->data, heap->capacity * sizeof(int));
        heap->arr = (int*) realloc(heap->arr, heap->capacity * sizeof(int));
    }

    heap->data[heap->size] = n;
    heap->arr[heap->size] = q;
    heap->size++;

    sift_up(heap, heap->size - 1);

}

void extract_min (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data);
    assert (heap->arr);

    heap->size--;
    heap->data[0] = heap->data[heap->size];
    heap->arr[0] = heap->arr[heap->size];

    sift_down (heap, 0);
}

void get_min (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data);

    printf ("%lld\n", heap->data[0]);
}

void decrease_key (struct Binary_heap *heap, int n, int x) {
    assert (heap);
    assert (heap->data);
    assert (heap->arr);

    for (int i = 0; i < heap->size; i++) {
        if (heap->arr[i] == n) {
            heap->data[i] = heap->data[i] - x;

            sift_up (heap, i);

            break;

        }

    }

}

void clear (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->arr);
    assert (heap->data);

    free (heap->arr);
    free (heap->data);
    free (heap);

}

int main() {
    struct Binary_heap* heap;
    heap = init(1);
    char a[20];

    int n, q = 1;
    scanf ("%lld", &n);

    while (n) {
        scanf("%s", a);

        if (strcmp(a, "insert") == 0) {
            int t;
            scanf("%lld", &t);
            insert (heap, t, q);
        }
        else if (strcmp(a, "extractMin") == 0)
        {
            extract_min (heap);
        }
        else if (strcmp(a, "getMin") == 0)
        {
            get_min (heap);
        }
        else if (strcmp(a, "decreaseKey") == 0)
        {
            int t, x;
            scanf("%lld %lld", &t, &x);
            decrease_key (heap, t, x);
        }

        n--;
        q++;
    }
    return 0;
}



