#include <stdio.h>
#include "grid.h"
#include "bras.h"
#include "poly.h"
#include "flood.h"

void scenarioLine() {
    Grid grid;
    clearGrid(grid);
    int x0, y0, x1, y1;
    printf("Start of section (x0 y0): ");
    scanf("%d %d", &x0, &y0);
    printf("End of section (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    drawLine(grid, x0, y0, x1, y1, WALL);
    printGrid(grid);
}

void scenarioPolygonFill() {
    Grid grid;
    clearGrid(grid);
    int n;
    printf("Number of points (3..8): ");
    scanf("%d", &n);
    int xs[MAX_SIDES], ys[MAX_SIDES];
    for (int i = 0; i < n; i++) {
        printf("Point %d (x y): ", i + 1);
        scanf("%d %d", &xs[i], &ys[i]);
    }
    drawPolygon(grid, xs, ys, n, WALL);
    printf("\nContour:\n");
    printGrid(grid);
    int sx, sy;
    printf("Start point of filling (x y): ");
    scanf("%d %d", &sx, &sy);
    int filled = floodFill(grid, sx, sy);
    printf("\nFilled: %d\n", filled);
    printGrid(grid);
}

int main() {
    while (1) {
        int choice;
        printf("\n1 - section\n2 - polygon + filling\n0 - leave\n");
        printf("Choice: ");
        scanf("%d", &choice);
        if (choice == 0) break;
        if (choice == 1) scenarioLine();
        else if (choice == 2) scenarioPolygonFill();
    }
    return 0;
}