#include <stdio.h>
#include <stdlib.h>

#include "algos.h"
#include "matrix.h"

typedef struct node {
    struct node *oldNode;
    unsigned char programCase;
} node_t;

node_t node = {NULL, 8};
node_t *lastNode = &node;
//changer pour node_t * lastNode = NULL;
unsigned char programCase;

node_t *jumpInProgram(char newProgramCase) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->oldNode = lastNode;
    newNode->programCase = programCase;
    programCase = newProgramCase;
    return newNode;
}

void jumpBack() {
    node_t *temp = lastNode->oldNode;
    programCase = lastNode->programCase;
    free(lastNode);
    lastNode = temp;
}

void doAction(enum Action action) {
    switch (action) {
        case FORWARD:
            move();
            break;
        case TURN_LEFT:
            turnLeft();
            break;
        case TURN_RIGHT:
            turnRight();
            break;
        case PAINT_RED:
            paintRed();
            break;
        case PAINT_BLUE:
            paintBlue();
            break;
        case F1:
            lastNode = jumpInProgram(0);
            break;
        case F2:
            lastNode = jumpInProgram(3);
            break;
    }
}

void resetStatus() {
    coords.x = 5;
    coords.y = 10;
    direction = RIGHT;
    resetMatrix();  // pas necessaire a chaque fois...
    while (lastNode->programCase != 8) {
        jumpBack();  // permet de free tous les nodes
    }
    programCase = 0;
}

int main() {
    unsigned long long n = 28ll * 28ll * 28ll * 28ll * 28ll * 28ll * 28ll;
    for (unsigned long long i = 0; i < n; i++) {
        printf("Tested programs: %llu\r", i);
        resetStatus();
        Program program = generateNextProgram();

        for (int step = 0; step < 100 && !gameLost() && !gameWon(); step++) {
            if (programCase == PROGRAM_LENGTH - 1 || programCase == 2) {
                // 2 correspond a F1_LENGTH - 1
                if (lastNode->programCase == 8) {
                    // printf("t");
                    // printProgram(program);
                    break;
                } else {
                    jumpBack();
                }
            }
            struct Instruction instruction = program[programCase];
            programCase = programCase + 1;

            switch (instruction.condition) {
                case CD_NONE:
                    doAction(instruction.action);
                    break;
                case CD_RED:
                    if (isRed()) {
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

            // printCoords();
        }

        if (gameWon()) {
            printf("this program succeeded\n\n\n");
            printProgramVerbose(program);
        } else if (gameLost()) {
            // printf("this program failed\n\n\n");
            // printf("f-");
        } else {
            // printf("this program terminated without finding the star\n\n\n");
            // printf("i-");
        }
        // printf("\n");

        // free(program);
    }
    return 0;
}