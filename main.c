#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "algos.h"

typedef struct node {
    struct node * oldNode;
    unsigned char programCase;
} node_t;

node_t node = {NULL, -1};
node_t * lastNode = &node;
unsigned char programCase = 8;

void jumpInProgram(char newProgramCase) {
    node_t * newNode = malloc(sizeof(node_t));
    newNode->oldNode = lastNode;
    newNode->programCase = programCase;
    programCase = newProgramCase;
    lastNode = newNode;
}

void jumpBack() {
    node_t * temp = lastNode->oldNode;
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
            jumpInProgram(0);
            break;
        case F2:
            jumpInProgram(3);
            break;
    }

}

int main() {

    for (int i = 0 ; i < 100 ; i++) {

        Program program = generateNextProgram();
        //printProgram(program);

        coords.x = 5 ;
        coords.y = 10;
        direction = RIGHT;

        while (!gameLost() && !gameWon()) {


            if (programCase == PROGRAM_LENGTH - 1 || PROGRAM_LENGTH == 2){
                //2 correspond a F1_LENGTH - 1
                jumpBack();
                if (programCase == 8) {
                    printf("This program terminated without finding the star");
                    printProgram(program);
                    break;
                }
            }
            struct Instruction instruction = program[programCase];
            programCase = programCase + 1;

            switch(instruction.condition) {
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

            //printCoords();

        }

        if (gameWon()) {
            printf("this program succeeded\n\n\n");
            printProgram(program);
        }

        if (gameLost()) {
            //printf("this program failed\n\n\n");
            printf("f-");
        }
    }
    return 0;
}