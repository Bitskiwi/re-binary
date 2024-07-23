// INCLUDES

#include "head/world.h"
#include "head/img.h"
#include "head/screen.h"
#include "assets/tiles/checker.h"
#include "assets/tiles/grass.h"
#include <stdio.h>
#include <string.h>

// DRAW TILE

screen draw_tile(screen surf, world map, tile til, int x, int y){
	surf = draw_img(surf, x * 10, y * 10, map.sprites[til]);
	return surf;
}

// WORLD CONSTRUCTOR

world init_world(int w, int h){
	img checker_img = init_img(checker_data, 10, 10);
	img grass_img = init_img(grass_data, 10, 10);
	img sprites[4] = {checker_img, grass_img};
	world inst;
	for(int i = 0; i < 4; i++){
		inst.sprites[i] = sprites[i];
	}
	inst.w = w;
	inst.h = h;
	for(int y = 0; y < inst.h; y++){
		for(int x = 0; x < inst.w; x++){
			inst.tiles[y][x] = checker;
		}
	}
	inst.tiles[1][1] = grass;
	return inst;
}

// RENDER WORLD

screen draw_world(screen surf, world map){
	for(int y = 0; y < map.h; y++){
		for(int x = 0; x < map.w; x++){
			surf = draw_tile(surf, map, map.tiles[y][x], x, y);
		}
	}
	return surf;
}
