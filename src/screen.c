// INCLUDES

#include "head/screen.h"
#include <stdio.h>
#include <string.h>

// SCREEN CONSTRUCTOR

screen init_screen(int w, int h){
	screen inst;
	inst.w = w;
	inst.h = h;
	return inst;
}

// SCREEN DRAW

screen draw_screen(screen surface, int x, int y, char draw_color[8]){
	if(x >= 0 && x <= surface.w){
		if(y >= 0 && y <= surface.h){
			strcpy(surface.colors[y][x], draw_color);
		}
	}
	return surface;
}

// SCREEN FILL

screen fill_screen(screen surface, char fill_color[8]){
	for(int y = 0; y < surface.h; y++){
		for(int x = 0; x < surface.w; x++){
			surface = draw_screen(surface, x, y, fill_color);
		}
	}
	return surface;
}

// SCREEN RENDER

void render_screen(screen surface){
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
