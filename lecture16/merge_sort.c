/* Lecture 16: merge sort */

#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Functions */

void merge(int *a, size_t left_size, size_t right_size) {
    // Create temporary array
    size_t merged_size = left_size + right_size;
    int   *merged      = malloc(merged_size * sizeof(int));

    // Merge both arrays into temporary array
    size_t left_index  = 0;
    size_t right_index = 0;
    for (size_t merged_index = 0; merged_index < merged_size; merged_index++) {
    	// Copy left array if none in right
    	if (right_index == right_size) {
    	    merged[merged_index] = a[left_index++];
    	    continue;
	}

    	// Copy right array if none in left
    	if (left_index == left_size) {
    	    merged[merged_index] = a[left_size + right_index++];
    	    continue;
	}

	// Copy the lesser of the left or right arrays
	if (a[left_index] <= a[left_size + right_index]) {
    	    merged[merged_index] = a[left_index++];
	} else {
    	    merged[merged_index] = a[left_size + right_index++];
	}
    }

    // Copy temporary array to original array
    memcpy(a, merged, merged_size * sizeof(int));
    free(merged);
}

void merge_sort(int *a, size_t n) {
    // Base case: Only one element, so do nothing
    if (n <= 1) {
    	return;
    }

    // Divide: Split sequence in half
    size_t left_size  = n / 2;
    size_t right_size = n - left_size;

    // Conquer: Recursively sort subsequences
    merge_sort(a, left_size);
    merge_sort(a + left_size, right_size);

    // Combine: Merge sorted subsequences
    merge(a, left_size, right_size);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int *numbers = malloc(NUMBERS_MAX*sizeof(int));
    srand(time(NULL));
    make_random_array(numbers, NUMBERS_MAX);
    merge_sort(numbers, NUMBERS_MAX);
    free(numbers);
    return 0;
}
