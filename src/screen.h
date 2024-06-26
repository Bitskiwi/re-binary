// HEADER GUARD

#ifndef SCREEN_H
#define SCREEN_H

// COLORS

char BLK[8];
char RED[8];
char GRN[8];
char YEL[8];
char BLU[8];
char MAG[8];
char CYN[8];
char WHT[8];
char CLR[8];

// SCREEN STRUCTURE

struct screen;

// SCREEN CONSTRUCTOR

struct screen new_screen(int w, int h);

// SCREEN DRAW

struct screen draw_screen(struct screen surface, int x, int y, char draw_color[8]);

// SCREEN FILL

struct screen fill_screen(struct screen surface, char fill_color[8]);

// SCREEN RENDER

void render_screen(struct screen surface);

#endif
