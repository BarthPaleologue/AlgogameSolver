#include <stdlib.h>
#include "stack.h"


node_t * lastNode = NULL;

node_t *jumpInProgram(char newProgramCase, char * programCasePointer) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->oldNode = lastNode;
    newNode->programCase = *programCasePointer;
    *programCasePointer = newProgramCase;
    return newNode;
}

void jumpBack(char * programCasePointer) {
    node_t *temp = lastNode->oldNode;
    *programCasePointer = lastNode->programCase;
    free(lastNode);
    lastNode = temp;
}
