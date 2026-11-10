#include <stdio.h>
#include "grid.h"

void clearGrid(Grid g) {
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            g[y][x] = EMPTY;
}

void setPixel(Grid g, int x, int y, char symbol) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;
    g[y][x] = symbol;
}

char getPixel(Grid g, int x, int y) {
    return g[y][x];
}

void printGrid(Grid g) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++)
            putchar(g[y][x]);
        putchar('\n');
    }
}