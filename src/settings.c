// INCLUDES

#include <stdio.h>

// SETTINGS FILE

FILE *config;

// READ THE FILE

void read_config(char target[1000]){
	config = fopen("settings", "r");
	fgets(target, 1000, config);
	fclose(config);
}


