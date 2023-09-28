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

void	map_insert(Map *m, int key, int value) {
    size_t bucket = hash(key) % m->capacity;

    if (map_lookup(m, key) >= 0) {
    	return;
    }

    m->buckets[bucket] = pair_create(key, value, m->buckets[bucket]);
    m->size++;
}

int	map_lookup(Map *m, int key) {
    size_t bucket = hash(key) % m->capacity;

    for (Pair *curr = m->buckets[bucket]; curr; curr = curr->next)
    	if (curr->key == key)
    	    return curr->value;

    return -1;
}
