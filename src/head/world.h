// HEADER GUARD

#ifndef WORLD_H
#define WORLD_H

// INCLUDES

#include "img.h"
#include "entity.h"

// TILE STRUCTURE

typedef struct {
	int x;
	int y;
	int w;
	int h;
} tile;

// TILE CODES

typedef enum {
	grass,
	dirt,
	stone,
} tile_code;

// TILE CONSTRUCTOR

tile init_tile();

#endif
