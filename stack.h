typedef struct node {
    struct node *oldNode;
    unsigned char programCase;
} node_t;

extern node_t *lastNode;

node_t *jumpInProgram(char newProgramCase, char * programCasePointer);
void jumpBack(char * programCasePointer);