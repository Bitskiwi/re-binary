// INCLUDES

#include <stdio.h>
#include <string.h>

// COLORS

char BLACK[8] = "\e[0;30m";
char RED[8] = "\e[0;31m";
char GREEN[8] = "\e[0;32m";
char YELLOW[8] = "\e[0;33m";
char BLUE[8] = "\e[0;34m";
char MAGENTA[8] = "\e[0;35m";
char CYAN[8] = "\e[0;36m";
char WHITE[8] = "\e[0;37m";
char CLEAR[8] = "clear";

// SCREEN STRUCTURE

struct screen{
	char colors[100][100][8];
	int w;
	int h;
};

// SCREEN CONSTRUCTOR

struct screen new_screen(int w, int h){
	struct screen instance;
	instance.w = w;
	instance.h = h;
	return instance;
}

// SCREEN DRAW

struct screen draw_screen(struct screen surface, int x, int y, char draw_color[8]){
	strcpy(surface.colors[y][x], draw_color);
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
