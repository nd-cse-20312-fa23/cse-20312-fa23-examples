/* duplicates3.c: sorting version */

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "library.h"

/* Functions */

int intcmp(const void *a, const void *b) {
    int *ia = (int *)a;
    int *ib = (int *)b;
    return *ia - *ib;
}

bool has_duplicates(int *array, size_t n) {
    qsort(array, n, sizeof(int), intcmp);

    for (size_t i = 1; i < n; i++)
    	if (array[i] == array[i - 1])
    	    return true;

    return false;
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int numbers[NUMBERS_MAX] = {0};
    srand(time(NULL));
    make_random_array(numbers, NUMBERS_MAX);
    puts(has_duplicates(numbers, NUMBERS_MAX) ? "Yeah" : "Nope");
    return 0;
}
