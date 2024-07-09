// INCLUDES

#include "head/screen.h"
#include <stdio.h>
#include <string.h>

// SCREEN CONSTRUCTOR

struct screen new_screen(int w, int h){
	struct screen instance;
	instance.w = w;
	instance.h = h;
	return instance;
}

// SCREEN DRAW

struct screen draw_screen(struct screen surface, int x, int y, char draw_color[8]){
	if(x >= 0 && x <= surface.w){
		if(y >= 0 && y <= surface.h){
			strcpy(surface.colors[y][x], draw_color);
		}
	}
	return surface;
}

// SCREEN FILL

struct screen fill_screen(struct screen surface, char fill_color[8]){
	for(int y = 0; y < surface.h; y++){
		for(int x = 0; x < surface.w; x++){
			surface = draw_screen(surface, x, y, fill_color);
		}
	}
	return surface;
}

// SCREEN RENDER

void render_screen(struct screen surface){
	for(int y = 0; y < surface.h; y++){
		for(int x = 0; x < surface.w; x++){
			printf(surface.colors[y][x]);
			for(int i = 0; i < 2; i++){
				printf("\u2588");
			}
		}
		printf("\n");
	}
	printf("\e[0;0m");
}
