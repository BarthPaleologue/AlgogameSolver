#ifndef STACK_H
#define STACK_H

/**
 * @brief Uses the stack to store the programPointer value before assigning the new one.
 *
 * @param newProgramPointer New value for the programPointer
 * @param programPointer the programPointer itself
 */
void jumpInProgram(int newProgramPointer, int *programPointer);

/**
 * @brief Uses the stack to restore the precent value of the programPointer.
 *
 * @param programPointer the programPointer itself
 */
void jumpBack(int *programPointer);

/**
 * @brief Returns 1 iff the stack is empty.
 */
char stackEmpty();

/**
 * @brief Empties the stack
 */
void initStack();

#endif