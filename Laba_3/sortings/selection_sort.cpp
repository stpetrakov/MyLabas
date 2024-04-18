#include "square_sortings.h"

void selection_sort(int* a, const size_t n) 
{ 
    size_t minimum; 
    for (size_t i = 0; i < n-1; i++) { 
        minimum = i;

        for (size_t j = i + 1; j < n; j++) 
            if (a[j] < a[minimum]) 
                minimum = j; 

        if (minimum != i) {
            swap (&a[i], &a[minimum], int);
        }
    } 
} 