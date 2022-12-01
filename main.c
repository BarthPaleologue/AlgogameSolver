#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "generator.h"
#include "level_specifics.h"
#include "matrix.h"
#include "stack.h"

char programCase;

void doAction(enum Action action) {
    switch (action) {
        case FORWARD:
            move();
            return;
        case TURN_LEFT:
            turnLeft();
            return;
        case TURN_RIGHT:
            turnRight();
            return;
        case PAINT_RED:
            paintRed();
            declareWasPainted();
            return;
        case PAINT_BLUE:
            paintBlue();
            declareWasPainted();
            return;
        case F1:
            lastNode = jumpInProgram(0, &programCase);
            return;
        case F2:
            lastNode = jumpInProgram(F1_LENGTH, &programCase);
            return;
    }
    return;
}

void updateProgramCase() {
    if (programCase == PROGRAM_LENGTH - 1 || programCase == F1_LENGTH - 1) {
        programCase = -1;
    } else {
        programCase = programCase + 1;
    }
}

void resetStatus() {
    coords.x = 5;
    coords.y = 10;
    direction = RIGHT;
    numberOfStars = 1;
    if (wasPainted()) {
        resetMatrix();  // pas necessaire a chaque fois...
    }
    while (lastNode != NULL) {
        jumpBack(&programCase);  // permet de free tous les nodes
    }
    programCase = 0;
}

void kill_handler(int signo) {
    if (signo == SIGINT) {
        printProgramState();
        writeProgramStateToFile("./program_state.txt");
        exit(0);
    }
}

int main() {
    signal(SIGINT, kill_handler);

    // read from program_state.txt and update programState
    readProgramStateFromFile("./program_state.txt");

    /*char programArray[7][2] = {
        {F2, CD_NONE},
        {PAINT_BLUE, CD_NONE},
        {F1, CD_NONE},
        {FORWARD, CD_RED},
        {PAINT_RED, CD_BLUE},
        {F2, CD_RED},
        {TURN_LEFT, CD_NONE}};

    Program p = getProgramFromVerboseArray(programArray);

    printProgramVerbose(p);*/

    initPath();
    initMatrix();
    resetMatrix();
    printf("\n\n\n");

    //printMatrix(matrix);

    unsigned long long n = 0;

    Program program = NULL;

    while ((program = generateNextProgram()) != NULL) {
        resetStatus();

        for (int step = 0; step < 120 && !gameLost() && !gameTerminated() && !gameWon(); step++) {
            struct Instruction instruction = program[programCase];

            updateProgramCase();

            if (isStar()) {
                numberOfStars--;
            }

            switch (instruction.condition) {
                case CD_NONE:
                    doAction(instruction.action);
                    break;
                case CD_RED:
                    if (isRed() != 0) {
                        doAction(instruction.action);
                    }
                    break;
                case CD_ORANGE:
                    if (isOrange()) {
                        doAction(instruction.action);
                    }
                    break;
                case CD_BLUE:
                    if (isBlue()) {
                        doAction(instruction.action);
                    }
                    break;
            }
            while (programCase == -1) {
                if (lastNode == NULL) {
                    // printf("t");
                    // printProgram(program);
                    declareGameTerminated();
                    break;
                }
                jumpBack(&programCase);
            }
            /*printf("instruction : %d %d", instruction.action, instruction.condition);
            printCoords();
            printf("\ndirection : %d\n\n", direction);
            printMatrix(matrix);*/
        }

        if (gameWon()) {
            printf("this program succeeded\n\n\n");
            printProgramVerbose(program);
        } else if (gameLost()) {
            // printf("this program failed\n\n\n");
            //  printf("f-");
        } else if (gameTerminated()) {
            // printf("this program terminated without finding the star\n\n\n");
            //  printf("i-");
        }

        printf("Tested programs: %llu\r", ++n);

        free(program);
    }
    return 0;
}
