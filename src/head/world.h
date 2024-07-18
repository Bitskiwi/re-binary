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

// WORLD STRUCTURE

typedef struct {
	tile tiles[100][100];
	int w;
	int h;
} world;

// TILE CONSTRUCTOR

tile init_tile(tile_type type, int x, int y);

// WORLD CONSTRUCTOR

world init_world();

// RENDER WORLD

void render_world(world wrld);

#endif
