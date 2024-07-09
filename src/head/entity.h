// HEADER GUARD

#ifndef ENTITY_H
#define ENTITY_H

// ENTITY STRUCTURE

struct entity{
	int x;
	int y;
	int w;
	int h;
};

// ENTITY CONSTRUCTOR

struct entity new_entity(int x, int y, int w, int h);

// DIRECTION ENUM

enum direction {
	south,
	east,
	north,
	west
};

#endif
