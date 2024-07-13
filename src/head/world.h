// HEADER GUARD

#ifndef WORLD_H
#define WORLD_H

// INCLUDES

#include "img.h"

// TILE CODES

typedef enum {
	grass,
	dirt,
	stone,
} tile_type;

// TILE STRUCTURE

typedef struct {
	tile_type type;
	int x;
	int y;
	int w;
	int h;
	img sprite;
} tile;

// TILE CONSTRUCTOR

tile init_tile();

#endif
