#include "stack.h"

#include <stdlib.h>

node_t *stackPointer = NULL;

void jumpInProgram(int newprogramPointer, int *programPointerPointer) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->previousNode = stackPointer;
    newNode->programPointer = *programPointerPointer;
    *programPointerPointer = newprogramPointer;
    stackPointer = newNode;
}

void jumpBack(int *programPointerPointer) {
    node_t *temp = stackPointer->previousNode;
    *programPointerPointer = stackPointer->programPointer;
    free(stackPointer);
    stackPointer = temp;
}
