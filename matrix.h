#ifndef matrix_h
#define matrix_h

#include "utils_struct.h"

/**
 * @brief The possible colors of the cells.
 */
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

extern unsigned int matrixHeight;
extern unsigned int matrixWidth;

/**
 * @brief Current matrix modified by the program being executed.
 */
extern char** matrix;

/**
 * @brief The unaltered level matrix with colors.
 */
extern char** matrixColorBackup;

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