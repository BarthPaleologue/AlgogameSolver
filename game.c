#include <stdio.h>
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
            return jumpInProgram(0, &programPointer);
        case F2:
            return jumpInProgram(F1_LENGTH, &programPointer);
    }
}

void updateProgramPointer() {
    if (programPointer == PROGRAM_LENGTH - 1 || programPointer == F1_LENGTH - 1 || programPointer == F1_LENGTH + F2_LENGTH - 1 || programPointer == F1_LENGTH + F2_LENGTH + F3_LENGTH - 1 || programPointer == F1_LENGTH + F2_LENGTH + F3_LENGTH + F4_LENGTH - 1)
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

    starsCounter = numberOfStars;

    if (wasPainted()) {
        resetMatrix();  // pas necessaire a chaque fois...
    }
    while (stackPointer != NULL) {
        jumpBack(&programPointer);  // permet de free tous les nodes
    }
    programPointer = 0;
}

void executeProgram(Program program) {

    for (int step = 0; step < MAX_EXECUTION_ITERATIONS && !gameLost(); step++) {
        struct Instruction instruction = program[programPointer];


        updateProgramPointer();

        doInstruction(instruction.action, instruction.condition);

        while (programPointer == -1) {
            if (stackPointer == NULL) {
                return;
            }
            jumpBack(&programPointer);
        }
        /*printf("instruction : %d %d", instruction.action, instruction.condition);
        printCoords();
        printf("\ndirection : %d\n\n", direction);
        printf("%d\n", starsCounter);
        printMatrix(matrix);*/

        eatStar();

        if (gameWon()) {
            return;
        }
    }
}