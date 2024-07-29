// INCLUDES

#include "head/screen.h"
#include "head/img.h"
#include "head/direction.h"
#include "head/character.h"
#include "head/world.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>

// MAIN

int main(){
	screen surface = init_screen(80, 40);
	printf("> initialized screen");
	//surface = fill_screen(surface, GRN);

	world map = init_world(10, 10);
	printf("> initialized world");

	map = spawn_biome(map, grass, 1, 1, 2);
	printf("> spawned biomes");

	character terry = init_character(0, 0, 10, 10);
	printf("> initialized character");

	getchar();

	char key = 's';
	system("clear");
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	while(1){
		printf("\033[H");
		terry = control_character(key, terry);
		surface = draw_world(surface, map);
		surface = draw_character(surface, terry);
		render_screen(surface);
		key = getchar();
		if(key == 'q'){
			break;
		}
	}
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	system("clear");
}
