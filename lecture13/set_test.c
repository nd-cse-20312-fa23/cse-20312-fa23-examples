/* Lecture 13: Set */

#include "set.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Main Execution */

int main(int argc, char *argv[]) {
    int  d[] = {4, 6, 6, 3, 7, -1};
    Set *s   = set_create();

    for (int *p = d; *p >= 0; p++)
	set_add(s, *p);

    set_dump(s);

    for (int i = 0; i < 10; i++)
    	printf("contains(%d) ? %d\n", i, set_contains(s, i));

    set_delete(s);
    return 0;
}
