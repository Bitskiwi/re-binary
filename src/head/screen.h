// HEADER GUARD

#ifndef SCREEN_H
#define SCREEN_H

// COLORS

// COLORS

char BLK[8] = "\e[0;30m";
char RED[8] = "\e[0;31m";
char GRN[8] = "\e[0;32m";
char YEL[8] = "\e[0;33m";
char BLU[8] = "\e[0;34m";
char MAG[8] = "\e[0;35m";
char CYN[8] = "\e[0;36m";
char WHT[8] = "\e[0;37m";
char CLR[8] = "CLR";

// SCREEN STRUCTURE

struct screen{
	char colors[100][100][8];
	int w;
	int h;
};

// SCREEN CONSTRUCTOR

struct screen new_screen(int w, int h);

// SCREEN DRAW

struct screen draw_screen(struct screen surface, int x, int y, char draw_color[8]);

// SCREEN FILL

struct screen fill_screen(struct screen surface, char fill_color[8]);

// SCREEN RENDER

void render_screen(struct screen surface);

#endif
