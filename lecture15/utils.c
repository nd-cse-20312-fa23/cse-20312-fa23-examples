/* Lecture 15: Utilities */

#include "utils.h"

#include <stdio.h>

/* Functions */

inline void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void dump_array(int *a, size_t n) {
    printf("%d", a[0]);
    for (size_t i = 1; i < n; i++)
	printf(" %d", a[i]);
    printf("\n");
}
