#include "all_sortings.h"

struct KaryHeap {
    int *a; // Массив для хранения элементов кучи
    int capacity; // Максимальная вместимость кучи
    int size; // Текущий размер кучи
    int k; // Количество детей у каждого элемента
};

struct KaryHeap *createKaryHeap(int capacity, int k) {
    struct KaryHeap *karyHeap;
    karyHeap = (struct KaryHeap *)malloc(sizeof(struct KaryHeap));
    karyHeap->capacity = capacity;
    karyHeap->size = 0;
    karyHeap->a = (int *)malloc(capacity * sizeof(int));
    karyHeap->k = k;
    return karyHeap;
}

void heapify(struct KaryHeap *karyHeap, int i) {
    int largest = i;
    int child;

    for (int j = 1; j <= karyHeap->k; j++) {
        child = karyHeap->k * i + j;
        if (child < karyHeap->size && karyHeap->a[child] > karyHeap->a[largest])
            largest = child;
    }

    if (largest != i) {
        int temp = karyHeap->a[i];
        karyHeap->a[i] = karyHeap->a[largest];
        karyHeap->a[largest] = temp;

        heapify(karyHeap, largest);
    }
}

void heap_sort(int *a, int n, int k) {
    struct KaryHeap *karyHeap = createKaryHeap(n, k);

    // Заполняем кучу элементами из массива
    for (int i = 0; i < n; i++) {
        karyHeap->a[i] = a[i];
        karyHeap->size++;
    }

    for (int i = (n - 1) / k; i >= 0; i--) {
        heapify(karyHeap, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = karyHeap->a[0];
        karyHeap->a[0] = karyHeap->a[i];
        karyHeap->a[i] = temp;

        karyHeap->size--;

        heapify(karyHeap, 0);
    }

    for (int i = 0; i < n; i++) {
        a[i] = karyHeap->a[i];
    }

    free(karyHeap->a);
    free(karyHeap);
}

