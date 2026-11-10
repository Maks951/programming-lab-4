#include <stdlib.h>
#include "bras.h"

void drawLine(Grid g, int x0, int y0, int x1, int y1, char symbol) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x1-x0) < 0 ? -1 : ((x1-x0) > 0 ? 1 : 0);
    int sy = (y1-y0) < 0 ? -1 : ((y1-y0) > 0 ? 1 : 0);

    int err = dx - dy;
    int x = x0, y = y0;

    do {
        setPixel(g, x, y, symbol);
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x += sx; }
        if (e2 <  dx) { err += dx; y += sy; }
    } while (x != x1 || y != y1);
}