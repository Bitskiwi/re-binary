// INCLUDES

#include "img.h"
#include <string.h>
#include "screen.c"

// TEST IMG


// IMG STRUCTURE

struct img{
	char colors[20][20][8];
	int w;
	int h;
};

// IMG CONSTRUCTOR

struct img new_img(char *colors[20][20], int w, int h){
	struct img instance;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			strcpy(instance.colors[y][x], colors[y][x]);
		}
	}
	instance.w = w;
	instance.h = h;
	return instance;
}

// RENDER IMG

struct screen draw_img(struct screen surface, int start_x, int start_y, struct img source){
	for(int y = 0; y < source.h; y++){
		for(int x = 0; x < source.w; x++){
			if(strcmp(source.colors[y][x], "CLR") != 0){
				surface = draw_screen(surface, x + start_x, y + start_y, source.colors[y][x]);
			}
		}
	}
	return surface;
}
