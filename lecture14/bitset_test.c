/* Lecture 14: Bitset */

#include "bitset.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Main Execution */

int main(int argc, char *argv[]) {
    int  d[] = {4, 6, 6, 3, 7, -1};
    Bitset b = 0;

    for (int *p = d; *p >= 0; p++)
	bitset_add(&b, *p);

    printf("bitset: %lu\n", b);

    for (int i = 0; i < 10; i++)
    	printf("contains(%d) ? %d\n", i, bitset_contains(&b, i));
    
    for (int *p = d; *p >= 0; p++)
	bitset_remove(&b, *p);

    printf("bitset: %lu\n", b);
    return 0;
}
