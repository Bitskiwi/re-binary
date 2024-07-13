// HEADER GAURD

#ifndef CHARACTER_H
#define CHARACTER_H

// INCLUDES

#include "img.h"
#include "direction.h"

// CHARACTER STRUCTURE

typedef struct {
	int x;
	int y;
	int w;
	int h;
	int speed;
	img sprite;
	img idle[4];
	direction facing;
} character;

// CHARACTER CONSTRUCTOR

character init_character(int x, int y, int w, int h);

// CHARACTER RENDER

screen draw_character(screen surface, character terry);

// CHARACTER CONTROLLER

character control_character(char key, character terry);

#endif
