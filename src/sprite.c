// INCLUDES

#include "screen.c"

// TEST SPRITE


// SPRITE STRUCTURE

struct sprite{
	char colors[20][20][8];
	int w;
	int h;
};

// SPRITE CONSTRUCTOR

struct sprite new_sprite(char colors[20][20][8], int w, int h){
	struct sprite instance;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			strcpy(instance.colors[y][x], colors[y][x]);
		}
	}
	instance.w = w;
	instance.h = h;
	return instance;
}

// RENDER SPRITE

struct screen draw_sprite(struct screen surface, int start_x, int start_y, struct sprite source){
	for(int y = 0; y < source.h; y++){
		for(int x = 0; x < source.w; x++){
			surface = draw_screen(surface, x + start_x, y + start_y, source.colors[y][x]);
		}
	}
	return surface;
}
