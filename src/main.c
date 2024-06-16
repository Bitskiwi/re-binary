// INCLUDES

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include "sprite.c"
#include "settings.c"

// MAIN

int main(){
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	struct screen surface = new_screen(100, 50);
	surface = fill_screen(surface, GRN);
	
	char *sprite_data[20][20] = {
		{CLR,CLR,CLR,YEL,YEL,YEL,YEL,CLR,CLR,CLR},
		{CLR,CLR,YEL,YEL,YEL,YEL,YEL,YEL,CLR,CLR},
		{CLR,CLR,BLK,BLK,WHT,WHT,BLK,BLK,CLR,CLR},
		{CLR,CYN,RED,RED,RED,RED,RED,RED,CYN,CLR},
		{CYN,CYN,BLU,RED,RED,RED,RED,BLU,CYN,CYN},
		{CYN,CYN,BLU,BLU,RED,RED,BLU,BLU,CYN,CYN},
		{WHT,WHT,BLU,BLU,BLU,BLU,BLU,BLU,WHT,WHT},
		{WHT,WHT,BLU,BLU,BLU,BLU,BLU,BLU,WHT,WHT},
		{CLR,CLR,BLK,BLK,CLR,CLR,BLK,BLK,CLR,CLR},
		{CLR,BLK,BLK,BLK,CLR,CLR,BLK,BLK,BLK,CLR},
	};
	struct sprite test = new_sprite(sprite_data, 10, 10);
	while(1){
		system("clear");
		surface = draw_sprite(surface, 1, 1, test);
		render_screen(surface);
		char key = getchar();
		if(key == 'q'){
			break;
		}
		if(key == 'r'){
			surface = fill_screen(surface, RED);
		}
		if(key == 'p'){
			surface = draw_screen(surface, 1, 1, BLU);
		}
	}
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
