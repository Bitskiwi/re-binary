// HEADER GAURD

#ifndef CHARACTER_H
#define CHARACTER_H

// CHARACTER STRUCTURE

struct character;

// CHARACTER CONSTRUCTOR

struct character init_character(int x, int y, int w, int h);
// CHARACTER RENDER

struct screen draw_character(struct screen surface, struct character player);

// CHARACTER CONTROLLER

struct character control_character(char key, struct character player);

#endif
