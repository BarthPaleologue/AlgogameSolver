#include "stack.h"

#include <stdlib.h>

node_t *lastNode = NULL;

node_t *jumpInProgram(int newProgramCase, int *programCasePointer) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->oldNode = lastNode;
    newNode->programCase = *programCasePointer;
    *programCasePointer = newProgramCase;
    return newNode;
}

void jumpBack(int *programCasePointer) {
    node_t *temp = lastNode->oldNode;
    *programCasePointer = lastNode->programCase;
    free(lastNode);
    lastNode = temp;
}
