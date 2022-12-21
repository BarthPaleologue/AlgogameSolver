#include "game.h"

#include "dartAgent.h"
#include "matrix.h"

void eatStar() {
    if (matrix[coords.y][coords.x] != CASE_STAR) {
        return;
    }
    matrix[coords.y][coords.x] = matrixColorBackup[coords.y][coords.x];
    declareWasPainted();
    starsCounter--;
}

char gameLost() {
    return matrix[coords.y][coords.x] == CASE_WHITE;
}

char gameWon() {
    return (starsCounter == 0);
}