typedef struct node {
    struct node *oldNode;
    unsigned char programCase;
} node_t;

extern node_t *lastNode;

node_t *jumpInProgram(unsigned char newProgramCase, unsigned char * programCasePointer);
void jumpBack(unsigned char * programCasePointer);