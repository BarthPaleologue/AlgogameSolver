typedef struct node {
    struct node *previousNode;
    unsigned int programPointer;
} node_t;

extern node_t *stackPointer;

/**
 * @brief Updates the stack pointer and the given programPointer with the new programPointer value
 *
 * @param newprogramPointer The new value for the programPointer
 * @param programPointerPointer A pointer to the global programPointer
 */
void jumpInProgram(int newprogramPointer, int *programPointerPointer);

/**
 * @brief Unstack the stack pointer and updates the given pointer to programPointer accordingly
 *
 * @param programPointerPointer A pointer to the global programPointer
 */
void jumpBack(int *programPointerPointer);