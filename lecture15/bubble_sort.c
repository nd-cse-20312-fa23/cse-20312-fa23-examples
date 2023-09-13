/* Lecture 15: bubble sort */

#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Functions */

void bubble_sort(int *a, size_t n) {
    bool swapped;
    do {
    	swapped = false;
    	for (size_t i = 1; i < n; i++) {
    	    if (a[i] < a[i - 1]) {
    	    	swap(&a[i], &a[i - 1]);
    	    	swapped = true;
		dump_array(a, n);
	    }
	}

    } while (swapped);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int    a[]  = {9, 2, 8, 6, 7};
    size_t alen = sizeof(a) / sizeof(int);

    dump_array(a, alen);
    bubble_sort(a, alen);
    return 0;
}
