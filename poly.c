#include "poly.h"
#include "bras.h"

void drawPolygon(Grid g, int xs[], int ys[], int n, char symbol) {
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        drawLine(g, xs[i], ys[i], xs[j], ys[j], symbol);
    }
}