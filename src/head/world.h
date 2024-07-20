// HEADER GUARD

#ifndef WORLD_H
#define WORLD_H

// INCLUDES

#include "img.h"
#include "screen.h"

// TILE TYPE ENUM

typedef enum {
	checker,
	grass,
	dirt,
	stone,
} tile;

// WORLD STRUCTURE

typedef struct {
	tile tiles[20][20];
	img sprites[4];
	int w;
	int h;
} world;

// DRAW TILE

screen draw_tile(screen surf, world map, tile til, int x, int y);

// WORLD CONSTRUCTOR

world init_world(int w, int h);

// RENDER WORLD

screen draw_world(screen surf, world map);

#endif
