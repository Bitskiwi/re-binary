// INCLUDES

#include "head/world.h"
#include "head/img.h"
#include "head/screen.h"
#include "sprites.h"
#include "assets/tiles/checker.h"
#include "assets/tiles/grass.h"
#include <stdio.h>
#include <string.h>

// DRAW TILE

screen draw_tile(screen surf, tile til, int x, int y){
	switch(til){
		case checker:
			surf = draw_img(surf, x * 10, y * 10, checker_img);
		case grass:
			surf = draw_img(surf, x * 10, y * 10, grass_img);
	}
	return surf;
}

// WORLD CONSTRUCTOR

world init_world(int w, int h){
	world inst;
	inst.w = w;
	inst.h = h;
	for(int y = 0; y < inst.h; y++){
		for(int x = 0; x < inst.w; x++){
			inst.tiles[y][x] = checker;
		}
	}
	return inst;
}

// RENDER WORLD

screen draw_world(screen surf, world map){
	for(int y = 0; y < map.h; y++){
		for(int x = 0; x < map.w; x++){
			surf = draw_tile(surf, map.tiles[y][x], x, y);
		}
	}
	return surf;
}
