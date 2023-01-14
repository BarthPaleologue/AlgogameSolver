#include <stdlib.h>
#include "stack.h"

typedef struct node {
    struct node *previousNode;
    unsigned int programPointer;
} node_t;

node_t *stackPointer = NULL;

void jumpInProgram(int newProgramPointer, int *programPointer) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->previousNode = stackPointer;
    newNode->programPointer = *programPointer;
    *programPointer = newProgramPointer;
    stackPointer = newNode;
}

void jumpBack(int *programPointer) {
    node_t *temp = stackPointer->previousNode;
    *programPointer = stackPointer->programPointer;
    free(stackPointer);
    stackPointer = temp;
}

char stackEmpty() {
    return (stackPointer == NULL);
}

void initStack() {
    while (stackPointer != NULL) {
        node_t *temp = stackPointer->previousNode;
        free(stackPointer);
        stackPointer = temp;
    }
}
