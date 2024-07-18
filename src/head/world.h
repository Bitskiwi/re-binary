// HEADER GUARD

#ifndef WORLD_H
#define WORLD_H

// INCLUDES

#include "img.h"
#include "screen.h"

// TILE CODES

typedef enum {
	checker,
	grass,
	dirt,
	stone,
} tile_type;

// TILE STRUCTURE

typedef struct {
	tile_type type;
	int w;
	int h;
	img sprite;
} tile;

// WORLD STRUCTURE

typedef struct {
	tile tiles[20][20];
	int w;
	int h;
} world;

// TILE CONSTRUCTOR

tile init_tile(tile_type type);

// WORLD CONSTRUCTOR

world init_world(int w, int h);

// RENDER WORLD

screen draw_world(screen surf, world wrld);

#endif
