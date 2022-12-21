#ifndef EXECPROG_H
#define EXECPROG_H

#include "generator.h"

/**
 * @brief Will execute the given program and update the game state until it is finished or a certain limit of instructions is reached
 *
 * @param program The given program to be executed
 */
void executeProgram(Program program);

/**
 * @brief Will reset the execution state of the program
 *
 */
void resetExecution();

#endif