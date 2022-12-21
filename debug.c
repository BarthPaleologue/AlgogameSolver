#include <stdio.h>

#include "colors.h"
#include "dartAgent.h"
#include "matrix.h"

void printMatrix(char** matrix, unsigned int matrixHeight, unsigned int matrixWidth) {
    for (unsigned int i = 0; i < matrixHeight; i++) {
        for (unsigned int j = 0; j < matrixWidth; j++) {
            switch (matrix[i][j]) {
                case CASE_WHITE:
                    printf(" ");
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
    printf("x : %d; y : %d\n", coords.x, coords.y);
}