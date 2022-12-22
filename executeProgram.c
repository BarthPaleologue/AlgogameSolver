#include "executeProgram.h"

#include <stdio.h>

#include "dartAgent.h"
#include "debug.h"
#include "game.h"
#include "level_specifics.h"
#include "matrix.h"
#include "stack.h"

/**
 * @brief Index of the next instruction to be fetched in the program.<br>
 * It is updated before the execution (thus its value changes twice if a function call is executed).
 * If the next instruction is unknown (end of a function), it is set to -1 temporally.
 */
static int programPointer;

static void updateProgramPointer();
static void doInstruction(enum Action action, enum Condition condition);
static void printExecutionInfo();

void initStack() {
    while (!stackEmpty()) {
        jumpBack(&programPointer);  // permet de free tous les nodes
    }
    programPointer = 0;
}

/**
 * @brief Updates the program pointer (in case the function ends, it is temporally set to -1).<br>
 * The program pointer is also modified : during the execution when a jump takes place;
 * after the execution to replace -1 by the right value.
 */
static void updateProgramPointer() {
    // TOTHINK : always test for F3_START even when there's no F3 ???
    if (programPointer == PROGRAM_LENGTH - 1 || programPointer == F2_START - 1 || programPointer == F3_START - 1 || programPointer == F4_START - 1) {
        programPointer = -1;
        // if we reach the end of a function, we set the pointer to a special value
    } else {
        programPointer = programPointer + 1;
        // otherwise we set the pointer to the next instruction
    }
}

/**
 * @brief Will filter the conditions and then do the given action which will update the game state.
 *
 * @param action The action of the instruction
 * @param condition The condition that is applied to the action
 */
static void doInstruction(enum Action action, enum Condition condition) {
    switch (condition) {
        case CD_NONE:
            break;
        case CD_RED:
            if (isRed()) break;
            return;  // if the condition is ot respected the instruction is not executed
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
            return declareWasPainted();  // shortened syntax : declareWasPainted returns void
        case PAINT_BLUE:
            paintBlue();
            return declareWasPainted();
        case PAINT_ORANGE:
            paintOrange();
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

void executeProgram(Program program) {
    initGame();

    for (int step = 0; step < MAX_EXECUTION_ITERATIONS; step++) {
        struct Instruction instruction = program[programPointer];

        updateProgramPointer();  // programPointer was already used
        // it is set for the next instruction fetch

        doInstruction(instruction.action, instruction.condition);

        while (programPointer == -1) {
            if (stackEmpty()) {
                return;
            }
            jumpBack(&programPointer);
        }

        printExecutionInfo();

        eatStar();

        if (gameWon() | gameLost()) {
            return;
        }
    }
}

/** @brief prints the position, direction, number of stars and matrix after each execution
 */
static void printExecutionInfo() {
    if (PRINT_EXEC_INFO) {
        printCoords();
        printf("\ndirection : %d\n\n", direction);
        printf("number of stars : %d\n", nbRemainingStars);
        printMatrix(matrix, matrixHeight, matrixWidth);
    }
}