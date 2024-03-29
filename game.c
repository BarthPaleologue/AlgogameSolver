#include "game.h"

#include "dartAgent.h"
#include "level_specifics.h"
#include "matrix.h"
#include "stack.h"

char nbRemainingStars;

void initGlobals() {
    initMatrix();
    nbRemainingStars = numberOfStars;
}

void initGame() {
    // this function resets all the nessecary parameters to test a new program

    coords.x = startingCoords.x;
    coords.y = startingCoords.y;

    direction = startingDirection;

    nbRemainingStars = numberOfStars;

    if (wasModified()) resetMatrix();
    initStack();
}

void eatStar() {
    if (matrix[coords.y][coords.x] != CASE_STAR) return;
    matrix[coords.y][coords.x] = matrixColorBackup[coords.y][coords.x];
    declareMapWasModified();
    nbRemainingStars--;
}

char gameLost() { return matrix[coords.y][coords.x] == CASE_WHITE; }

char gameWon() { return (nbRemainingStars == 0); }