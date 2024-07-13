// HEADER GUARD

#ifndef IMG_H
#define IMG_H

// INCLUDES

#include "screen.h"

// IMG STRUCTURE

typedef struct {
	char colors[20][20][8];
	int w;
	int h;
} img;

// IMG CONSTRUCTOR

img init_img(char *colors[20][20], int w, int h);

// RENDER IMG

screen draw_img(screen surface, int start_x, int start_y, img source);

#endif
