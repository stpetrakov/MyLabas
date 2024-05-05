#include "square_sortings.h"
#include "swap.h"

void selection_sort(int* a, const size_t n) { 
    for (size_t i = 0; i < n-1; i++) { 
        size_t minimum = i;

        for (size_t j = i + 1; j < n; j++) 
            if (a[j] < a[minimum]) 
                minimum = j; 

        if (minimum != i) {
            swap (a[i], a[minimum]);
        }
    } 
} 