#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "algos.h"
#include "matrix.h"
#include "stack.h"

unsigned char programCase;
char hasJumped;

char doAction(enum Action action) {
    switch (action) {
        case FORWARD:
            move();
            return 0;
        case TURN_LEFT:
            turnLeft();
            return 0;
        case TURN_RIGHT:
            turnRight();
            return 0;
        case PAINT_RED:
            paintRed();
            declareWasPainted();
            return 0;
        case PAINT_BLUE:
            paintBlue();
            declareWasPainted();
            return 0;
        case F1:
            lastNode = jumpInProgram(0, &programCase);
            return 1;
        case F2:
            lastNode = jumpInProgram(3, &programCase);
            return 1;
    }
    return 0;
}

void updateProgramCase(char hasJumped) {
    if (hasJumped) {
        return;
    }
    if (programCase == PROGRAM_LENGTH - 1 || programCase == 2) {
        // 2 correspond a F1_LENGTH - 1
        if (lastNode == NULL) {
            // printf("t");
            // printProgram(program);
            declareGameTerminated();
        } else {
            jumpBack(&programCase);
        }
    } else {
        programCase = programCase + 1;
    }
}

void resetStatus() {
    coords.x = 5;
    coords.y = 10;
    direction = RIGHT;
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
    FILE* file = fopen("./program_state.txt", "r");
    if (file) fscanf(file, "%hhd %hhd %hhd %hhd %hhd %hhd %hhd", &programState[0], &programState[1], &programState[2], &programState[3], &programState[4], &programState[5], &programState[6]);

    /*char programArray[7][2] = {
        {FORWARD, CD_RED},
        {F2, CD_NONE},
        {F1, CD_NONE},
        {TURN_LEFT, CD_ORANGE},
        {FORWARD, CD_NONE},
        {F2, CD_RED},
        {TURN_LEFT, CD_NONE}};

    Program p = getProgramFromVerboseArray(programArray);

    printProgramVerbose(p);*/

    resetMatrix();

    printMatrix(matrix);

    unsigned long long n = 0;

    Program program = NULL;

    while ((program = generateNextProgram()) != NULL) {
        resetStatus();

        for (int step = 0; step < 120 && !gameLost() && !gameWon() && !gameTerminated(); step++) {
            struct Instruction instruction = program[programCase];

            switch (instruction.condition) {
                case CD_NONE:
                    hasJumped = doAction(instruction.action);
                    break;
                case CD_RED:
                    if (isRed() != 0) {
                        hasJumped = doAction(instruction.action);
                    } else {
                        hasJumped = 0;
                    }
                    break;
                case CD_ORANGE:
                    if (isOrange()) {
                        hasJumped = doAction(instruction.action);
                    } else {
                        hasJumped = 0;
                    }
                    break;
                case CD_BLUE:
                    if (isBlue()) {
                        hasJumped = doAction(instruction.action);
                    } else {
                        hasJumped = 0;
                    }
                    break;
            }
            updateProgramCase(hasJumped);

            // printf("\n");
            // printCoords();
            // printf("\n%d\n\n", direction);
            // printMatrix(matrix);
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
        // printf("\n");

        printf("Tested programs: %llu\r", ++n);

        free(program);
    }
    return 0;
}
