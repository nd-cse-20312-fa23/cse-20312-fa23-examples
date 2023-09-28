/* map.h: Map Structure */

#pragma once

#include "pair.h"

#include <stdlib.h>

/* Constants */

#define	MAP_DEFAULT_CAPACITY	(1<<8)

/* Structure */

typedef struct {
    Pair ** buckets;
    size_t  capacity;
    size_t  size;
} Map;

/* Functions */

Map *	map_create();
void	map_delete(Map *m);

void	map_insert(Map *m, int key, int value);
int	map_lookup(Map *m, int key);

void	map_format(Map *m);
