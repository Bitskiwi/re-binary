// INCLUDES

#include <stdio.h>

// SETTINGS FILE

FILE *config;

// READ THE FILE

void readln_config(char target[50]){
	config = fopen("settings", "r");
	fgets(target, 50, config);
	fclose(config);
}
