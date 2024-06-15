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
	surface = fill_screen(surface, BLACK);
	
	char black[8];

	char sprite_data[20][20][8] = {
		{"\e[0;35m", "\e[0;35m", "\e[0;35m", black, "\e[0;35m"},
		{"\e[0;35m", "\e[0;35m", "\e[0;35m", "\e[0;35m", "\e[0;35m"},
		{"\e[0;35m", "\e[0;35m", "\e[0;35m", "\e[0;35m", "\e[0;35m"},
		{"\e[0;35m", "\e[0;35m", "\e[0;35m", "\e[0;35m", "\e[0;35m"},
		{"\e[0;35m", "\e[0;35m", "\e[0;35m", "\e[0;35m", "\e[0;35m"}
		/*{MAGENTA, BLACK, MAGENTA, BLACK, MAGENTA},
		{BLACK, MAGENTA, BLACK, MAGENTA, BLACK},
		{MAGENTA, BLACK, MAGENTA, BLACK, MAGENTA},
		{BLACK, MAGENTA, BLACK, MAGENTA, BLACK},
		{MAGENTA, BLACK, MAGENTA, BLACK, MAGENTA},
	*/};
	struct sprite test = new_sprite(sprite_data, 5, 5);
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
			surface = draw_screen(surface, 1, 1, BLUE);
		}
	}
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
