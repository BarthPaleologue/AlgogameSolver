#include <stdio.h>

#include "colors.h"
#include "dartAgent.h"
#include "matrix.h"

void printMatrix(char** matrix) {
    for (unsigned int i = 0; i < numberOfLines; i++) {
        for (unsigned int j = 0; j < numberOfColumns; j++) {
            switch (matrix[i][j]) {
                case CASE_WHITE:
                    printf("_");
                    break;
                case CASE_RED:
                    printf(RED "R" RESET);
                    break;
                case CASE_ORANGE:
                    printf(YELLOW "O" RESET);
                    break;
                case CASE_BLUE:
                    printf(CYAN "B" RESET);
                    break;
                case CASE_STAR:
                    printf(BOLDGREEN "*" RESET);
                    break;
                default:
                    printf(BOLDRED "?" RESET);  // should never happen
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