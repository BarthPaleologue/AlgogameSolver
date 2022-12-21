#include <stdio.h>
#include "matrix.h"

void printMatrix(char** matrix) {
    for (int i = 0; i < numberOfLines; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            if (i == coords.y && j == coords.x) {
                printf("X");
                continue;
            }
            switch (matrix[i][j]) {
                case CASE_WHITE:
                    printf("_");
                    break;
                case CASE_RED:
                    printf("R");
                    break;
                case CASE_ORANGE:
                    printf("O");
                    break;
                case CASE_BLUE:
                    printf("B");
                    break;
                case CASE_STAR:
                    printf("*");
                    break;
                default:
                    printf("?");  // should never happen
            }
        }
        printf("\n");
    }
}


void printCoords() {
    if (coords.x == startingCoords.x && coords.y == startingCoords.y) {
        return;
    }
    printf("x : %d; y : %d\n", coords.x, coords.y);
}