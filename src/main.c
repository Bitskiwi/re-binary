// INCLUDES

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include "character.c"

// MAIN

int main(){
	system("clear");
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	struct screen surface = new_screen(100, 50);
	surface = fill_screen(surface, GRN);

	struct character terry = init_character(0, 0, 10, 10);
	char key = 's';
	while(1){
		printf("\033[H");
		surface = fill_screen(surface, GRN);
		surface = draw_character(surface, terry);
		render_screen(surface);
		char key = getchar();
		if(key == 'q'){
			break;
		}
		terry = control_character(key, terry);
	}
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	system("clear");
}
