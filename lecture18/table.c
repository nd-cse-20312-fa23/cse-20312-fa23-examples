/* table.c: Hash Table */

#include "table.h"

#include <stdio.h>

/* Functions */

Table *	    table_create() {
    Table *t = calloc(1, sizeof(Table));
    if (t) {
    	t->capacity = TABLE_DEFAULT_CAPACITY;
    	t->buckets  = calloc(t->capacity, sizeof(int));
    }
    return t;
}

void	    table_delete(Table *t) {
    free(t->buckets);
    free(t);
}

uint32_t    hash(int value) {
    // https://stackoverflow.com/questions/11871245/knuth-multiplicative-hash
    return value * 2654435761;
}

void	    table_insert(Table *t, int value) {
    // No collision handling
    /*
    size_t bucket = hash(value) % t->capacity;
    t->buckets[bucket] = value;
    */

    // Linear probing
    ssize_t bucket = table_locate(t, value);
    t->buckets[bucket] = value;
    t->size++;
}

bool	    table_search(Table *t, int value) {
    // No collision handling
    /*
    size_t bucket = hash(value) % t->capacity;
    return t->buckets[bucket] == value;
    */
    
    // Linear probing
    ssize_t bucket = table_locate(t, value);
    return bucket >= 0 && t->buckets[bucket] == value;
}

void	    table_format(Table *t) {
    for (size_t bucket = 0; bucket < t->capacity; bucket++) {
    	printf("%d\n", t->buckets[bucket]);
    }
}

ssize_t	    table_locate(Table *t, int value) {
    size_t bucket = hash(value) % t->capacity;
    size_t probe  = 0;

    // Stop when:
    //	1. Run out of probes
    //	2. Find empty
    //	3. Find match
    while (probe < t->capacity && t->buckets[bucket] && t->buckets[bucket] != value) {
    	bucket = (bucket + 1) % t->capacity;
    	probe++;
    }

    return (probe < t->capacity) ? bucket : -1;
}
