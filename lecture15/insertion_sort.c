/* Lecture 15: insertion sort */

#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Functions */

void insertion_sort(int *a, size_t n) {
    for (size_t i = 1; i < n; i++) {
    	for (size_t j = i; j > 0 && a[j] < a[j - 1]; j--) {
    	    swap(&a[j], &a[j - 1]);
	}
	dump_array(a, n);
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int    a[]  = {9, 2, 8, 6, 7};
    size_t alen = sizeof(a) / sizeof(int);

    dump_array(a, alen);
    insertion_sort(a, alen);
    return 0;
}
