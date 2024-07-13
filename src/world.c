// INCLUDES

#include "head/world.h"
#include "head/img.h"
#include "assets/tiles/grass.h"
#include <stdio.h>

// TILE CONSTRUCTOR

tile init_tile(tile_type type, int x, int y){
	tile inst;
	switch(type){
		case grass:
			inst.type = type;
			inst.x = x;
			inst.y = y;
			inst.w = 10;
			inst.h = 10;
			inst.sprite = init_img(grass_data, 10, 10);
	}
	return inst;
}
