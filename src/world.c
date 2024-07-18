// INCLUDES

#include "head/world.h"
#include "head/img.h"
#include "head/screen.h"
#include "assets/tiles/checker.h"
#include "assets/tiles/grass.h"
#include <stdio.h>
#include <string.h>

// TILE CONSTRUCTOR

tile init_tile(tile_type type){
	tile inst;
	inst.w = 10;
	inst.h = 10;
	switch(type){
		case checker:
			inst.sprite = init_img(checker_data, 10, 10);
		case grass:
			inst.sprite = init_img(grass_data, 10, 10);
	}
	return inst;
}

// WORLD CONSTRUCTOR

world init_world(int w, int h){
	world inst;
	inst.w = w;
	inst.h = h;
	for(int y = 0; y < inst.h; y++){
		for(int x = 0; x < inst.w; x++){
			//inst.tiles[y][x] = init_tile(checker);
		}
	}
	return inst;
}

// RENDER WORLD

screen draw_world(screen surf, world wrld){
	for(int y = 0; y < wrld.h; y++){
		for(int x = 0; x < wrld.w; x++){
			draw_img(surf, x * 10, y * 10, wrld.tiles[y][x].sprite);
		}
	}
	return surf;
}
