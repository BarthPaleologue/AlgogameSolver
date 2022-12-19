#ifndef GAME_H
#define GAME_H

#include <stdlib.h>

#include "generator.h"
#include "level_specifics.h"
#include "matrix.h"
#include "stack.h"

/**
 * @brief Index of the next instruction to be fetched in the program.<br>
 * It is updated before the execution (thus its value changes twice if a function call is executed).
 * If the next instruction is unknown (end of a function), it is set to -1 temporally.
 */
extern int programPointer;

/**
 * @brief Will filter the conditions and then do the given action which will update the game state.
 *
 * @param action The action of the instruction
 * @param condition The condition that is applied to the action
 */
void doInstruction(enum Action action, enum Condition condition);

/**
 * @brief Updates the program pointer (in case the function ends, it is temporally set to -1).<br>
 * The program pointer is also modified : during the execution when a jump takes place;
 * after the execution to replace -1 by the right value.
 */
void updateProgramPointer();

/**
 * @brief Resets the game state : map, coordinates, number of stars, function call stack
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