/* map.h: Map Structure */

#pragma once

#include "pair.h"

#include <stdlib.h>

/* Constants */

#define	MAP_DEFAULT_CAPACITY	(1<<2)

/* Structure */

typedef struct {
    Pair ** buckets;
    size_t  capacity;
    size_t  size;
} Map;

/* Functions */

Map *	map_create();
void	map_delete(Map *m);

void	map_insert(Map *m, const char *key, int value);
int	map_lookup(Map *m, const char *key);

void	map_format(Map *m);
