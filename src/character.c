// INCLUDES

#include "entity.c"
#include "img.c"
#include "assets/player/idl"

// CHARACTER STRUCTURE

struct character{
	struct entity ent;
	struct img sprite;
	struct img idle[4]; 
	int facing;
};

// CHARACTER CONSTRUCTOR

struct character init_character(int x, int y, int w, int h){
	struct character instance;
	struct img idle[4] = {}  /////////////////////////////// WORK ON THIS LINE
	instance.ent = new_entity(x, y, w, h);
	for(int i = 0; i < 4; i++){
		instance.idle[i] = idle[i];
	}
	instance.facing = 3;
	instance.sprite = instance.idle[instance.facing - 1];
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
		player.facing = 3;
		player.ent.y -= 1;
	}
	if(key == 'a'){
		player.facing = 2;
		player.ent.x -= 1;
	}
	if(key == 's'){
		player.facing = 1;
		player.ent.y += 1;
	}
	if(key == 'd'){
		player.facing = 4;
		player.ent.x += 1;
	}
	player.sprite = player.idle[player.facing - 1];
	return player;
}
