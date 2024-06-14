// INCLUDES

#include <stdlib.h>
#include "screen.c"
#include "settings.c"

// MAIN

int main(){
	struct screen surface = new_screen(45, 30);
	surface = fill_screen(surface, BLACK);
	surface = draw_screen(surface, 3, 3, WHITE);
	render_screen(surface);
}
