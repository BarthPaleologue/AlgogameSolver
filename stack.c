#include "stack.h"

#include <stdlib.h>

node_t *lastNode = NULL;

node_t *jumpInProgram(int newprogramPointer, int *programPointerPointer) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->oldNode = lastNode;
    newNode->programPointer = *programPointerPointer;
    *programPointerPointer = newprogramPointer;
    return newNode;
}

void jumpBack(int *programPointerPointer) {
    node_t *temp = lastNode->oldNode;
    *programPointerPointer = lastNode->programPointer;
    free(lastNode);
    lastNode = temp;
}
