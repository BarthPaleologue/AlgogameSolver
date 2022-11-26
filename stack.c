#include <stdlib.h>
#include "stack.h"


node_t * lastNode = NULL;

node_t *jumpInProgram(unsigned char newProgramCase, unsigned char * programCasePointer) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->oldNode = lastNode;
    newNode->programCase = *programCasePointer;
    *programCasePointer = newProgramCase;
    return newNode;
}

void jumpBack(unsigned char * programCasePointer) {
    node_t *temp = lastNode->oldNode;
    *programCasePointer = lastNode->programCase;
    free(lastNode);
    lastNode = temp;
}
