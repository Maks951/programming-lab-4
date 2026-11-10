#ifndef GRID_H
#define GRID_H

#define WIDTH   40
#define HEIGHT  20

#define EMPTY   '.'
#define WALL    '#'
#define FILL    '*'

typedef char Grid[HEIGHT][WIDTH];

void clearGrid(Grid g);

void setPixel(Grid g, int x, int y, char symbol);

char getPixel(Grid g, int x, int y);

void printGrid(Grid g);

#endif