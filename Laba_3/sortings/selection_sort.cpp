#include "all_sortings.h"

void selection_sort(int* a, int n) 
{ 
    int mi; 
    for (int i = 0; i < n-1; i++) { 
        mi = i;

        for (int j = i + 1; j < n; j++) 
            if (a[j] < a[mi]) 
                mi = j; 

        if(mi != i) {
            int t = a[i];
            a[i] = a[mi];
            a[mi] = t;
        }
    } 
} 