/* table_test.c: Hash Table (Test) */

#include "table.h"

#include <stdio.h>

/* Constants */

const int DATA[] = {4, 6, 6, 3, 7, -1};

/* Main Execution */

int main(int argc, char *argv[]) {
    Table *t = table_create();

    for (const int *p = DATA; *p >= 0; p++) {
    	printf("hash(%d) = %u, %lu\n", *p, hash(*p), hash(*p) % t->capacity);
    }

    for (const int *p = DATA; *p >= 0; p++) {
    	table_insert(t, *p);
    }

    for (const int *p = DATA; *p >= 0; p++) {
    	printf("table_search(%d) ? %d\n", *p, table_search(t, *p));
    }

    table_format(t);
    table_delete(t);
    return 0;
}
