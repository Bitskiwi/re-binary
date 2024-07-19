// INCLUDES

#include "head/character.h"
#include "head/direction.h"
#include "head/img.h"

// CHARACTER CONSTRUCTOR

character init_character(int x, int y, int w, int h){
	img idle_s = init_img(idle_s_data, 10, 10);
	img idle_e = init_img(idle_e_data, 10, 10);
	img idle_n = init_img(idle_n_data, 10, 10);
	img idle_w = init_img(idle_w_data, 10, 10);
	img idle[4] = {idle_s_img, idle_e_img, idle_n_img, idle_w_img};
	character inst;
	inst.x = x;
	inst.y = y;
	inst.w = w;
	inst.h = h;
	inst.speed = 10;
	for(int i = 0; i < 4; i++){
		inst.idle[i] = idle[i];
	}
	inst.facing = south;
	inst.sprite = inst.idle[inst.facing];
	return inst;
}

// CHARACTER RENDER

screen draw_character(screen surface, character terry){
	surface = draw_img(surface, terry.x, terry.y, terry.sprite);
	return surface;
}

// CHARACTER CONTROLLER

character control_character(char key, character terry){
	if(key == 'w'){
		terry.facing = north;
		terry.y -= terry.speed;
	}
	if(key == 'a'){
		terry.facing = west;
		terry.x -= terry.speed;
	}
	if(key == 's'){
		terry.facing = south;
		terry.y += terry.speed;
	}
	if(key == 'd'){
		terry.facing = east;
		terry.x += terry.speed;
	}
	terry.sprite = terry.idle[terry.facing];
	return terry;
}
