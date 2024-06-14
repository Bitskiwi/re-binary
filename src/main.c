// INCLUDES

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include "screen.c"
#include "settings.c"

// MAIN

int main(){
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	struct screen surface = new_screen(80, 45);
	surface = fill_screen(surface, BLACK);
	while(1){
		system("clear");
		render_screen(surface);
		char key = getchar();
		if(key == 'q'){
			break;
		}
		if(key == 'r'){
			surface = fill_screen(surface, RED);
		}
	}
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
