/* Lecture 16: insertion sort */

#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Functions */

void insertion_sort(int *a, size_t n) {
    for (size_t i = 1; i < n; i++) {
    	for (size_t j = i; j > 0 && a[j] < a[j - 1]; j--) {
    	    swap(&a[j], &a[j - 1]);
	}
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int *numbers = malloc(NUMBERS_MAX*sizeof(int));
    srand(time(NULL));
    make_random_array(numbers, NUMBERS_MAX);
    insertion_sort(numbers, NUMBERS_MAX);
    free(numbers);
    return 0;
}
