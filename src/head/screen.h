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

// INTENSE COLORS

#define IBLK "\e[0;90m"
#define IRED "\e[0;91m"
#define IGRN "\e[0;92m"
#define IYEL "\e[0;93m"
#define IBLU "\e[0;94m"
#define IMAG "\e[0;95m"
#define ICYN "\e[0;96m"
#define IWHT "\e[0;97m"

// NO COLOR

#define CLR "CLR"

// SCREEN STRUCTURE

typedef struct {
	char colors[100][100][8];
	int w;
	int h;
} screen;

// SCREEN CONSTRUCTOR

screen init_screen(int w, int h);

// SCREEN DRAW

screen draw_screen(screen surface, int x, int y, char draw_color[8]);

// SCREEN FILL

screen fill_screen(screen surface, char fill_color[8]);

// SCREEN RENDER

void render_screen(screen surface);

#endif
