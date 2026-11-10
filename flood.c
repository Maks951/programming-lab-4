#include <stdio.h>
#include "flood.h"

#define STACK_SIZE (WIDTH * HEIGHT * 4 + 1) // оценка сверху - каждая клетка берется от каждого из соседей максимум по разу (4 раза) + стартовая точка

typedef struct { int x, y; } Point;

Point stack[STACK_SIZE];
int stackCurNum = 0;

void push(int x, int y) {
    if (stackCurNum >= STACK_SIZE) return;
    stack[stackCurNum].x = x;
    stack[stackCurNum].y = y;
    stackCurNum++;
}

Point pop() {
    return stack[--stackCurNum];
}

int floodFill(Grid g, int seedX, int seedY) {
    if (getPixel(g, seedX, seedY) == FILL) {
        printf("Already filled.\n");
        return 0;
    }
    if (getPixel(g, seedX, seedY) == WALL) {
        printf("Start point for filling.\n");
        return 0;
    }

    stackCurNum = 0;
    push(seedX, seedY);
    int countFilled = 0;

    while (stackCurNum > 0) {
        Point p = pop();
        if (p.x < 0 || p.x >= WIDTH || p.y < 0 || p.y >= HEIGHT) continue;
        if (g[p.y][p.x] != EMPTY) continue;

        g[p.y][p.x] = FILL;
        countFilled++;

        push(p.x + 1, p.y);
        push(p.x - 1, p.y);
        push(p.x,     p.y + 1);
        push(p.x,     p.y - 1);
    }
    return countFilled;
}