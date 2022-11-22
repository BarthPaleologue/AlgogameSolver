#include <stdio.h>

enum Direction {
    UP, DOWN, LEFT, RIGHT
};

struct Coords {
    int x;
    int y;
};

struct Coords coords = {0, 0};

void printCoords() {
    printf("%d;%d", coords.x, coords.y);
}

void move(struct Coords *coords, enum Direction direction) {
    switch (direction) {
        case UP:
            coords->y++;
            break;
        case DOWN:
            coords->y--;
            break;
        case LEFT:
            coords->x--;
            break;
        case RIGHT:
            coords->x++;
            break;
    }
}

int main() {

    printCoords();

    return 0;
}