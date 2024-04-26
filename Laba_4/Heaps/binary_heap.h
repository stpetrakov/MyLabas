#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <malloc.h>

typedef int T;

struct BinaryHeap {
    T* data;
    T size;
    T capacity;
};

struct BinaryHeap* init(T capacity);

void sift_up (struct BinaryHeap *heap, T i);

void sift_down (struct BinaryHeap *heap, T i) ;

void insert(struct BinaryHeap *heap, T n);

void clear(struct BinaryHeap *heap);

void line_heap(int* a, size_t size);

void norm_heap(int* a, size_t size);

#endif /* BINARY_HEAP_H */
