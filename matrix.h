#ifndef matrix_h
#define matrix_h

#include "utils_struct.h"

/*The matrix knows where you are and how close you're to the goal. It also knows how to erase all you work to retry.*/
extern unsigned int numberOfLines;
extern unsigned int numberOfColumns;

enum Color {
    CASE_WHITE,
    CASE_RED,
    CASE_ORANGE,
    CASE_BLUE,
    CASE_STAR
};
// if you're on CASE_WHITE, you lose
// if you're on CASE_STAR, you win a star

/**
 * Starting position.
 */
extern struct Coords startingCoords;

/**
 * @brief Current matrix modified by the program being executed.
 */
extern char** matrix;

extern char** matrixBackup;

extern char** matrixColorBackup;

/**
 * @brief Remaining stars.
 */
extern char starsCounter;

// GAME SUCCESS' WATCHERS

/**
 * @brief Total number of stars in the map.
 */
extern char numberOfStars;

// INITIALIZATIONS OF THE MATRIX

/**
 * @brief Sets the matrix to pre-execution state.
 */
void resetMatrix();

/**
 * @brief Sets the matrix using the paths to the maps.
 */
void initMatrix();

// other useful functions

/**
 * Sets the flag _MapWasPainted to 1.
 */
void declareWasPainted();

/**
 * Returns the flag _MapWasPainted and sets the flag to 0.
 */
char wasPainted();

#endif