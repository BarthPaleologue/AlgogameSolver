#include "game.h"

int programCase;

void doInstruction(enum Action action, enum Condition condition) {
    switch (condition) {
        case CD_NONE:
            break;
        case CD_RED:
            if (isRed()) break;
            return;
        case CD_ORANGE:
            if (isOrange()) break;
            return;
        case CD_BLUE:
            if (isBlue()) break;
            return;
    }
    switch (action) {
        case FORWARD:
            return move();
        case TURN_LEFT:
            return turnLeft();
        case TURN_RIGHT:
            return turnRight();
        case PAINT_RED:
            paintRed();
            return declareWasPainted();
        case PAINT_BLUE:
            paintBlue();
            return declareWasPainted();
        case F1:
            lastNode = jumpInProgram(0, &programCase);
            return;
        case F2:
            lastNode = jumpInProgram(F1_LENGTH, &programCase);
            return;
    }
}

void updateProgramCase() {
    if (programCase == PROGRAM_LENGTH - 1 || programCase == F1_LENGTH - 1)
        programCase = -1;
    else
        programCase = programCase + 1;
}

void resetStatus() {
    // coords.x = startingCoords.x;
    // startingCoords defini dans matrix
    coords.x = 5;
    coords.y = 10;

    // direction doit etre set dans level_specific
    // direction = startingDirection;
    direction = RIGHT;

    numberOfStars = 1;
    // starsCounter = numberOfStars;

    if (wasPainted()) {
        resetMatrix();  // pas necessaire a chaque fois...
    }
    while (lastNode != NULL) {
        jumpBack(&programCase);  // permet de free tous les nodes
    }
    programCase = 0;
}

void executeProgram(Program program) {
    for (int step = 0; step < 120 && !gameLost() && !gameTerminated() && !gameWon(); step++) {
        struct Instruction instruction = program[programCase];

        updateProgramCase();

        if (isStar()) numberOfStars--;

        doInstruction(instruction.action, instruction.condition);

        while (programCase == -1) {
            if (lastNode == NULL) {
                declareGameTerminated();
                break;
            }
            jumpBack(&programCase);
        }
    }
}