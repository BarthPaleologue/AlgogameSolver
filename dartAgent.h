#ifndef INSTRUCIMPL_H
#define INTRUCIMPL_H

#include "utils_struct.h"

/**
 * Current direction of the cursor.
 */
extern enum Direction direction;

/**
 * Coordinates on the map.
 * Careful, the position is at matrix[y][x].
 */

/**
 * Current position of the cursor.
 */
extern struct Coords coords;

// INSTRUCTIONS' IMPLEMENTATION

// 6 possible instructions' actions

/**
 * @brief Move the cursor forward.
 *
 */
void moveForward();

/**
 * @brief Turn the cursor to the right.
 *
 */
void turnRight();

/**
 * @brief Turn the cursor to the left.
 *
 */
void turnLeft();

/**
 * @brief Paint the current cell red.
 *
 */
void paintRed();

/**
 * @brief Paint the current cell blue.
 *
 */
void paintBlue();

/**
 * @brief Paint the current cell orange.
 *
 */
void paintOrange();

// 3 possible conditions on instructions

/**
 * @brief Check if the current cell is red.
 *
 * @return char 1 if the current cell is red, 0 otherwise.
 */
char isRed();

/**
 * @brief Check if the current cell is orange.
 *
 * @return char 1 if the current cell is orange, 0 otherwise.
 */
char isOrange();

/**
 * @brief Check if the current cell is blue.
 *
 * @return char 1 if the current cell is blue, 0 otherwise.
 */
char isBlue();

#endif