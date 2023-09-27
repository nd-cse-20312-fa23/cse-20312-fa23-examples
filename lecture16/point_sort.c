/* Lecture 16: Point Sort */

#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Type Definitions */

typedef int (*Comparison)(const void *a, const void *b);

typedef struct {
    int x;
    int y;
} Point;

/* Functions */

void merge(Point *a, size_t left_size, size_t right_size, Comparison cmp) {
    // Create temporary array
    size_t merged_size = left_size + right_size;
    Point *merged      = malloc(merged_size * sizeof(Point));

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
	if (cmp(&a[left_index], &a[left_size + right_index]) <= 0) {
    	    merged[merged_index] = a[left_index++];
	} else {
    	    merged[merged_index] = a[left_size + right_index++];
	}
    }

    // Copy temporary array to original array
    memcpy(a, merged, merged_size * sizeof(Point));
    free(merged);
}

void merge_sort(Point *a, size_t n, Comparison cmp) {
    // Base case: Only one element, so do nothing
    if (n <= 1) {
    	return;
    }

    // Divide: Split sequence in half
    size_t left_size  = n / 2;
    size_t right_size = n - left_size;

    // Conquer: Recursively sort subsequences
    merge_sort(a, left_size, cmp);
    merge_sort(a + left_size, right_size, cmp);

    // Combine: Merge sorted subsequences
    merge(a, left_size, right_size, cmp);
}

int compare_point_x(const void *a, const void *b) {
    const Point *pa = (const Point *)a;
    const Point *pb = (const Point *)b;
    return pa->x - pb->x;
}

int compare_point_y(const void *a, const void *b) {
    const Point *pa = (const Point *)a;
    const Point *pb = (const Point *)b;
    return pa->y - pb->y;
}

int compare_point_xy(const void *a, const void *b) {
    const Point *pa = (const Point *)a;
    const Point *pb = (const Point *)b;
    if (pa->x == pa->y)
	return pa->y - pb->y;
    else
	return pa->x - pb->x;
}

void dump_points(Point *a, size_t n) {
    for (size_t i = 0; i < n; i++) {
    	printf("x = %d, y = %d\n", a[i].x, a[i].y);
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    Point pa[] = {
	{3, 4},
	{3, 2},
	{2, 3},
	{2, 6},
	{5, 2},
	{2, 1},
    };
    size_t plen = sizeof(pa)/sizeof(Point);
    
    //merge_sort(pa, plen, compare_point_y);
    //merge_sort(pa, plen, compare_point_x);
    merge_sort(pa, plen, compare_point_xy);

    dump_points(pa, plen);
    return 0;
}
