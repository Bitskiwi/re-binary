// INCLUDES

#include "head/img.h"
#include "head/screen.h"
#include <string.h>

// IMG CONSTRUCTOR

img init_img(char *colors[20][20], int w, int h){
	img inst;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			strcpy(inst.colors[y][x], colors[y][x]);
		}
	}
	inst.w = w;
	inst.h = h;
	return inst;
}

// RENDER IMG

screen draw_img(screen surface, int start_x, int start_y, img source){
	for(int y = 0; y < source.h; y++){
		for(int x = 0; x < source.w; x++){
			if(strcmp(source.colors[y][x], "CLR") != 0){
				surface = draw_screen(surface, x + start_x, y + start_y, source.colors[y][x]);
			}
		}
	}
	return surface;
}
