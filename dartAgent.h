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

void move();
void turnRight();
void turnLeft();
void paintRed();
void paintBlue();
void paintOrange();

// 3 possible conditions on instructions

char isRed();
char isOrange();
char isBlue();

#endif