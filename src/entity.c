//INCLUDES

#include "entity.h"

// ENTITY STRUCTURE

struct entity{
	int x;
	int y;
	int w;
	int h;
};

// ENTITY CONSTRUCTOR

struct entity new_entity(int x, int y, int w, int h){
	struct entity instance;
	instance.x = x;
	instance.y = y;
	instance.w = w;
	instance.h = h;
}

// DIRECTION ENUM

enum direction {
	south,
	east,
	north,
	west
};
