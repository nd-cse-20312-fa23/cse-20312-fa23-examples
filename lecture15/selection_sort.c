/* Lecture 15: selection sort */

#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Functions */

void selection_sort(int *a, size_t n) {
    for (size_t i = 0; i < n; i++) {
    	size_t j_min = i;
    	for (size_t j = i + 1; j < n; j++)
    	    if (a[j] < a[j_min])
    	    	j_min = j;

    	swap(&a[i], &a[j_min]);
    	dump_array(a, n);
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int    a[]  = {9, 2, 8, 6, 7};
    size_t alen = sizeof(a) / sizeof(int);

    dump_array(a, alen);
    selection_sort(a, alen);
    return 0;
}
