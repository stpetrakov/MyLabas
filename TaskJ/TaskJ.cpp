#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Binary_heap {
    int *data_min; //отвечает за минимум
    int *data_max;  //отвечает за максимум
    int size;
    int capacity;
};

enum result {
    SUCCESS,
    ERROR
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
    assert (heap->data_min);

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
    assert (heap->data_max);

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
    assert (heap->data_min);

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
    assert (heap->data_max);

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

int insert (struct Binary_heap *heap, int n) {
    assert (heap);
    assert (heap->data_min);
    assert (heap->data_max);

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

    return SUCCESS;
}

int extract_min (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data_min);
    assert (heap->data_max);

    if (heap->size == 0)
        return ERROR;

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

        return mi;
    }
}

int get_min (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data_min);

    if (heap->size == 0)
        return ERROR;

    else
        return heap->data_min[0];
}

int extract_max (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data_min);
    assert (heap->data_max);

    if (heap->size == 0)
        return ERROR;

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

        return ma;
    }
}

int get_max (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data_max);

    if (heap->size == 0)
        return ERROR;

    else
        return heap->data_max[0];
}

int size (struct Binary_heap *heap) {
    assert (heap);

    return heap->size;
}

int clear (struct Binary_heap *heap) {
    assert (heap);
    assert (heap->data_max);
    assert (heap->data_min);

    heap->size = 0;
    return SUCCESS;

}

int main() {
    struct Binary_heap* heap;
    heap = init(1);
    char a[20];

    int n;
    if (scanf("%d", &n) != 1) {
        printf ("ERROR: scanf != 1");
        return 0;                
    }

    while (n) {
        scanf("%19s", a);
        assert (strlen(a) <= 19);

        if (strcmp (a, "insert") == 0) {
            int t;

            if (scanf("%d", &t) != 1) {
                printf ("ERROR: scanf != 1");
                return 0;                
            }

            if (insert (heap, t) == SUCCESS)
                printf ("ok\n");
        }
        else if (strcmp (a, "extract_min") == 0)
        {
            int result = extract_min (heap);
            if (result == ERROR)
                printf ("error\n");

            else
                printf ("%d\n", result);
        }
        else if (strcmp (a, "get_min") == 0)
        {
            int result = get_min (heap);
            if (result == ERROR)
                printf ("error\n");

            else
                printf ("%d\n", result);
        }
        else if (strcmp (a, "extract_max") == 0)
        {
            int result = extract_max (heap);
            if (result == ERROR)
                printf ("error\n");

            else
                printf ("%d\n", result);
        }
        else if (strcmp (a, "get_max") == 0)
        {
            int result = get_max (heap);
            if (result == ERROR)
                printf ("error\n");

            else
                printf ("%d\n", result);
        }
        else if (strcmp (a, "size") == 0)
        {
            printf ("%d\n", size (heap));
        }
        else if (strcmp (a, "clear") == 0)
        {
            if (clear (heap) == SUCCESS)
                printf ("ok\n");
        }

        n--;
    }
    return 0;
}


