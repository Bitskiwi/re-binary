// INCLUDES

#include "character.h"
#include "entity.h"
#include "img.h"
#include "assets/terry/idle_s.h"
#include "assets/terry/idle_e.h"
#include "assets/terry/idle_n.h"
#include "assets/terry/idle_w.h"

// CHARACTER STRUCTURE

struct character{
	struct entity ent;
	struct img sprite;
	struct img idle[4]; 
	enum direction facing;
};

// CHARACTER CONSTRUCTOR

struct character init_character(int x, int y, int w, int h){
	struct img idle_s = new_img(idle_s_data, 10, 10);
	struct img idle_e = new_img(idle_e_data, 10, 10);
	struct img idle_n = new_img(idle_n_data, 10, 10);
	struct img idle_w = new_img(idle_w_data, 10, 10);
	struct img idle[4] = {idle_s, idle_e, idle_n, idle_w};
	struct character instance;
	instance.ent = new_entity(x, y, w, h);
	for(int i = 0; i < 4; i++){
		instance.idle[i] = idle[i];
	}
	instance.facing = south;
	instance.sprite = instance.idle[instance.facing];
	return instance;
}

// CHARACTER RENDER

struct screen draw_character(struct screen surface, struct character player){
	surface = draw_img(surface, player.ent.x, player.ent.y, player.sprite);
	return surface;
}

// CHARACTER CONTROLLER

struct character control_character(char key, struct character player){
	if(key == 'w'){
		player.facing = north;
		player.ent.y -= 10;
	}
	if(key == 'a'){
		player.facing = west;
		player.ent.x -= 10;
	}
	if(key == 's'){
		player.facing = south;
		player.ent.y += 10;
	}
	if(key == 'd'){
		player.facing = east;
		player.ent.x += 10;
	}
	player.sprite = player.idle[player.facing];
	return player;
}
