/* Lecture 17: quick sort */

#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Functions */

void partition(int *a, size_t n, size_t *pivot_index) {
    int    pivot_value = a[0];	// Pick first value as pivot
    size_t left_index  = 1;
    size_t right_index = n - 1;

    // Swap values > pivot to the right and items < pivot to the left
    while (left_index < right_index) {
    	// Move left index until we find value > pivot
    	while (left_index < n && a[left_index] <= pivot_value)
    	    left_index++;

	// Move right index until we find value < pivot
	while (a[right_index] > pivot_value)
	    right_index--;

	// Swap left and right
	if (left_index < right_index)
	    swap(&a[left_index], &a[right_index]);
    }

    // Swap pivot into place
    *pivot_index = right_index;
    swap(&a[0], &a[*pivot_index]);
}

void quick_sort(int *a, size_t n) {
    // Base case: Only one element, so do nothing
    if (n <= 1) {
    	return;
    }

    // Divide: Select pivot and partition array
    size_t pivot_index = 0;
    partition(a, n, &pivot_index);
    size_t left_size  = pivot_index;
    size_t right_size = n - pivot_index - 1;

    // Conquer: Recursively sort subsequences
    quick_sort(a, left_size);
    quick_sort(a + left_size + 1, right_size);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int *numbers = malloc(NUMBERS_MAX*sizeof(int));
    srand(time(NULL));
    make_random_array(numbers, NUMBERS_MAX);
    quick_sort(numbers, NUMBERS_MAX);
    free(numbers);
    return 0;
}
