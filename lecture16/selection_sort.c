/* Lecture 16: selection sort */

#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Functions */

void selection_sort(int *a, size_t n) {
    for (size_t i = 0; i < (n - 1); i++) {
    	size_t j_min = i;
    	for (size_t j = i + 1; j < n; j++)
    	    if (a[j] < a[j_min])
    	    	j_min = j;

    	swap(&a[i], &a[j_min]);
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int *numbers = malloc(NUMBERS_MAX*sizeof(int));
    srand(time(NULL));
    make_random_array(numbers, NUMBERS_MAX);
    selection_sort(numbers, NUMBERS_MAX);
    free(numbers);
    return 0;
}
