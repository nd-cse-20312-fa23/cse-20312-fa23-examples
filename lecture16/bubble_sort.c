/* Lecture 16: bubble sort */

#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Functions */

void bubble_sort(int *a, size_t n) {
    bool swapped;
    do {
    	swapped = false;
    	for (size_t i = 1; i < n; i++) {
    	    if (a[i] < a[i - 1]) {
    	    	swap(&a[i], &a[i - 1]);
    	    	swapped = true;
	    }
	}

    } while (swapped);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int *numbers = malloc(NUMBERS_MAX*sizeof(int));
    srand(time(NULL));
    make_random_array(numbers, NUMBERS_MAX);
    bubble_sort(numbers, NUMBERS_MAX);
    free(numbers);
    return 0;
}
