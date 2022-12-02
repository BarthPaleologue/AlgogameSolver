#include "game.h"

int programPointer;

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
            return jumpInProgram(F1_START, &programPointer);
        case F2:
            return jumpInProgram(F2_START, &programPointer);
        case F3:
            return jumpInProgram(F3_START, &programPointer);
        case F4:
            return jumpInProgram(F4_START, &programPointer);
    }
}

void updateProgramPointer() {
    if (programPointer == F2_START - 1 || programPointer == F3_START - 1 || programPointer == F4_START - 1 || programPointer == PROGRAM_LENGTH - 1)
        programPointer = -1;
    else
        programPointer = programPointer + 1;
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
    while (stackPointer != NULL) {
        jumpBack(&programPointer);  // permet de free tous les nodes
    }
    programPointer = 0;
}

void executeProgram(Program program) {
    for (int step = 0; step < MAX_EXECUTION_ITERATIONS && !gameLost() && !gameTerminated(); step++) {
        struct Instruction instruction = program[programPointer];

        updateProgramPointer();

        if (isStar()) numberOfStars--;

        if (gameWon()) return;

        doInstruction(instruction.action, instruction.condition);

        while (programPointer == -1) {
            if (stackPointer == NULL) {
                declareGameTerminated();
                break;
            }
            jumpBack(&programPointer);
        }
    }
}