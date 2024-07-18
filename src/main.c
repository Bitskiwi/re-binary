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

// MAIN

int main(){
	system("clear");
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	screen surface = init_screen(80, 40);
	//surface = fill_screen(surface, GRN);

	world map = init_world(10, 10);
	character terry = init_character(0, 0, 10, 10);
	char key = 's';
	while(1){
		printf("\033[H");
		char key = getchar();
		if(key == 'q'){
			break;
		}
		terry = control_character(key, terry);
		surface = draw_world(surface, map);
		surface = draw_character(surface, terry);
		render_screen(surface);
	}
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	system("clear");
}
