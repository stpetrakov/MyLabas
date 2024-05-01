#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef int64_t T;

struct Binary_heap {
    T* data;
    T* arr;
    T size;
    T capacity;
};


void swap (T* a, T* b) {
    T t = *a;
    *a = *b;
    *b = t;
}

struct Binary_heap* init (T capacity) {
    struct Binary_heap* heap;
    heap = (struct Binary_heap*) calloc(1, sizeof(struct Binary_heap));
    assert (heap);

    heap->data = (T*) calloc (capacity, sizeof(T));
    heap->arr = (T*) calloc (capacity, sizeof(T));
    heap->capacity = capacity;

    assert (heap->data);

    heap->size = 0;

    return heap;
}

void sift_up (struct Binary_heap *heap, T i) {
    assert (heap);

    while (heap->data[(i - 1)/2] > heap->data[i]) {
        swap (&heap->data[i], &heap->data[(i - 1)/2]);
        swap (&heap->arr[i], &heap->arr[(i - 1)/2]);

        i = (i - 1)/2;
    }
}

void sift_down (struct Binary_heap *heap, T i) {
    assert (heap);

    while (2*i + 1 < heap->size) {
        T left = 2 * i + 1;
        T right = 2 * i + 2;
        T j = left;

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

void insert (struct Binary_heap *heap, T n, T q) {
    assert (heap);
    assert (heap->data);
	assert (heap->arr);

    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (T*) realloc(heap->data, heap->capacity * sizeof(T));
        heap->arr = (T*) realloc(heap->arr, heap->capacity * sizeof(T));
    }

    heap->data[heap->size] = n;
    heap->arr[heap->size] = q;
    heap->size++;

    sift_up (heap, heap->size - 1);

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

int get_min (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data);

    return (heap->data[0]);
}

void decrease_key (struct Binary_heap *heap, T n, T x) {
    assert (heap);
    assert (heap->data);
    assert (heap->arr);

    for (T i = 0; i < heap->size; i++) {
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

    T n, q = 1;
    scanf ("%lld", &n);

    while (n > 0) {
        scanf("%s", a);

        if (strcmp(a, "insert") == 0) {
            T t;
            scanf("%lld", &t);
            insert (heap, t, q);
        }
        else if (strcmp(a, "extractMin") == 0)
        {
            extract_min (heap);
        }
        else if (strcmp(a, "getMin") == 0)
        {
            printf ("%lld\n", get_min (heap));
        }
        else if (strcmp(a, "decreaseKey") == 0)
        {
            T t, x;
            scanf("%lld %lld", &t, &x);
            decrease_key (heap, t, x);
        }

        n--;
        q++;
    }
    return 0;
}



