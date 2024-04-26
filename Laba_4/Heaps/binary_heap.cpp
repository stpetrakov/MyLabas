#include "binary_heap.h"
#include "../Tests/tests.h"

void swap (T* a, T* b) {
    T t = *a;
    *a = *b;
    *b = t;
}

struct BinaryHeap* init (T capacity) {
    struct BinaryHeap* heap;
    heap = (struct BinaryHeap*) calloc(1, sizeof(struct BinaryHeap));
    assert (heap);

    heap->data = (T*) calloc (capacity, sizeof(T));
    heap->capacity = capacity;

    assert (heap->data);

    heap->size = 0;

    return heap;
}

void build_heap_linear(struct BinaryHeap *heap) {
    assert(heap);
    assert(heap->data);
    assert(heap->size > 0);

    for (T i = (heap->size - 1) / 2; i >= 0; i--) {
        sift_down(heap, i);
    }
}

void sift_up (struct BinaryHeap *heap, T i) {
    assert (heap);

    while (heap->data[(i - 1)/2] > heap->data[i]) {
        swap (&heap->data[i], &heap->data[(i - 1)/2]);

        i = (i - 1)/2;
    }
}

void sift_down (struct BinaryHeap *heap, T i) {
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
        i = j;
    }
}

void insert (struct BinaryHeap *heap, T n) {
    assert (heap);
    assert (heap->data);

    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (T*) realloc(heap->data, heap->capacity * sizeof(T));
    }

    heap->data[heap->size] = n;
    heap->size++;

    sift_up(heap, heap->size - 1);

}

void clear (struct BinaryHeap *heap) {
    assert (heap);
    assert (heap->data);

    free (heap->data);
    free (heap);

}

void line_heap (int* a, size_t size) {
    BinaryHeap* heap = (BinaryHeap*) malloc(sizeof(BinaryHeap));
    heap->data = a;
    heap->size = size;
    heap->capacity = size;

    build_heap_linear (heap);
}

void norm_heap (int* a, size_t size) {
    struct BinaryHeap* heap;
    heap = init(1);

    for (int i = 0; i < size; i++) {
        insert (heap, a[i]);
    }
}



