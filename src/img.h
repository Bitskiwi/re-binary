// HEADER GUARD

#ifndef IMG_H
#define IMG_H

// IMG STRUCTURE

struct img;

// IMG CONSTRUCTOR

struct img new_img(char *colors[20][20], int w, int h);


// RENDER IMG

struct screen draw_img(struct screen surface, int start_x, int start_y, struct img source);

#endif
