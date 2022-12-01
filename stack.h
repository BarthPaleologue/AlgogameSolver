typedef struct node {
    struct node *oldNode;
    unsigned int programPointer;
} node_t;

extern node_t *lastNode;

node_t *jumpInProgram(int newprogramPointer, int *programPointerPointer);
void jumpBack(int *programPointerPointer);