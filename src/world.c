// INCLUDES

#include "head/world.h"
#include "head/img.h"
#include "assets/tiles/grass.h"
#include <stdio.h>

// TILE CONSTRUCTOR

tile init_tile(tile_type type, int x, int y){
	tile inst;
	inst.x = x;
	inst.y = y;
	inst.w = 10;
	inst.h = 10;
	char *img_data[10][10];
	switch(type){
		case checker:
			img_data = checker_data
		case grass:
			img_data = grass_data;
	}
	inst.sprite = init_img(img_data, 10, 10);
	return inst;
}

// WORLD CONSTRUCTOR

world init_world(int w, int h){
	world inst;
	inst.w = w;
	inst.h = h;
	return inst;
}

// RENDER WORLD

void render_world(world wrld){
	
}
