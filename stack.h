typedef struct node {
    struct node *oldNode;
    unsigned int programCase;
} node_t;

extern node_t *lastNode;

node_t *jumpInProgram(int newProgramCase, int *programCasePointer);
void jumpBack(int *programCasePointer);