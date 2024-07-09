// HEADER GAURD

#ifndef CHARACTER_H
#define CHARACTER_H

// INCLUDES

#include "img.h"
#include "entity.h"

// CHARACTER STRUCTURE

struct character {
	struct entity ent;
	struct img sprite;
	struct img idle[4];
	enum direction facing;
};

// CHARACTER CONSTRUCTOR

struct character init_character(int x, int y, int w, int h);

// CHARACTER RENDER

struct screen draw_character(struct screen surface, struct character player);

// CHARACTER CONTROLLER

struct character control_character(char key, struct character player);

#endif
