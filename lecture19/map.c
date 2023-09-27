/* map.c: Map Structure */

#include "map.h"
#include "hash.h"

#include <stdio.h>
#include <string.h>

/* Functions */

Map *	map_create() {
    Map *m = calloc(1, sizeof(Map));
    if (m) {
    	m->capacity = MAP_DEFAULT_CAPACITY;
    	m->buckets  = calloc(m->capacity, sizeof(Pair *));
    }
    return m;
}

void	map_delete(Map *m) {
    for (size_t bucket = 0; bucket < m->capacity; bucket++) {
    	if (m->buckets[bucket])
	    pair_delete(m->buckets[bucket]);
    }

    free(m->buckets);
    free(m);
}

void	map_insert(Map *m, const char *key, int value) {
    size_t bucket = hash(key, strlen(key)) % m->capacity;

    if (map_lookup(m, key) >= 0) {
    	return;
    }

    m->buckets[bucket] = pair_create(key, value, m->buckets[bucket]);
    m->size++;
}

int	map_lookup(Map *m, const char *key) {
    size_t bucket = hash(key, strlen(key)) % m->capacity;

    for (Pair *curr = m->buckets[bucket]; curr; curr = curr->next)
    	if (strcmp(curr->key, key) == 0)
    	    return curr->value;

    return -1;
}

void	map_format(Map *m) {
    for (size_t bucket = 0; bucket < m->capacity; bucket++) {
    	printf("Bucket %lu: ", bucket);
	for (Pair *curr = m->buckets[bucket]; curr; curr = curr->next)
	    printf(" {%s: %d}", curr->key, curr->value);
	printf("\n");
    }
}
