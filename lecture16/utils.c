/* Lecture 16: Utilities */

#include "utils.h"

#include <stdio.h>

/* Functions */

inline void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void dump_array(int *a, size_t n) {
    for (size_t i = 0; i < n; i++)
	printf("%d\n", a[i]);
}

void make_random_array(int *array, size_t n) {
    for (size_t i = 0; i < n; i++) {
    	array[i] = rand() % (n*n);
    }
}
