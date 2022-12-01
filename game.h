#ifndef GAME_H
#define GAME_H

#include <stdlib.h>

#include "generator.h"
#include "level_specifics.h"
#include "matrix.h"
#include "stack.h"

/**
 * @brief The index of the current instruction in the program
 *
 */
extern int programPointer;

/**
 * @brief Will filter the conditions and then do the given action which will update the game state
 *
 * @param action The action of the instruction
 * @param condition The condition that is applied to the action
 */
void doInstruction(enum Action action, enum Condition condition);

/**
 * @brief Updates the program pointer and takes care of the size of the different functions accordingly
 *
 */
void updateProgramPointer();

/**
 * @brief Resets the game state : map and coordinates
 *
 */
void resetStatus();

/**
 * @brief Will execute the given program and update the game state until it is finished or a certain limit of instructions is reached
 *
 * @param program The given program to be executed
 */
void executeProgram(Program program);

#endif