// INCLUDES

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include "character.c"

// MAIN

int main(){
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	struct screen surface = new_screen(100, 50);
	surface = fill_screen(surface, GRN);
	char *idle_s_data[20][20] = {
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
	struct img idle_s = new_img(idle_s_data, 10, 10);
	
	char *idle_n_data[20][20] = {
		{CLR,CLR,CLR,YEL,YEL,YEL,YEL,CLR,CLR,CLR},
		{CLR,CLR,YEL,YEL,YEL,YEL,YEL,YEL,CLR,CLR},
		{CLR,CLR,WHT,WHT,WHT,WHT,WHT,WHT,CLR,CLR},
		{CLR,CYN,RED,RED,RED,RED,RED,RED,CYN,CLR},
		{CYN,CYN,BLU,CYN,CYN,CYN,CYN,BLU,CYN,CYN},
		{CYN,CYN,BLU,BLU,BLU,BLU,BLU,BLU,CYN,CYN},
		{WHT,WHT,BLU,BLU,BLU,BLU,BLU,BLU,WHT,WHT},
		{WHT,WHT,BLU,BLU,BLU,BLU,BLU,BLU,WHT,WHT},
		{CLR,CLR,BLK,BLK,CLR,CLR,BLK,BLK,CLR,CLR},
		{CLR,BLK,BLK,BLK,CLR,CLR,BLK,BLK,BLK,CLR},
	};
	struct img idle_n = new_img(idle_n_data, 10, 10);
	struct img idle_w = idle_s;
	struct img idle_e = idle_n;
	struct img idle[4] = {idle_s, idle_e, idle_n, idle_w};
	struct character player = new_character(0, 0, 10, 10, idle);
	char key = 's';
	while(1){
		system("clear");
		surface = draw_character(surface, player);
		render_screen(surface);
		char key = getchar();
		if(key == 'q'){
			break;
		}
		player = control_character(key, player);
	}
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
