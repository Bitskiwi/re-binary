// HEADER GUARD

#ifndef SCREEN_H
#define SCREEN_H

// COLORS

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define CLR "CLR"

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
