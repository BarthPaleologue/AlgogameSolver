#ifndef matrix_h
#define matrix_h

#include "utils_struct.h"

enum Color {
    CASE_WHITE,
    CASE_RED,
    CASE_ORANGE,
    CASE_BLUE,
    CASE_STAR
};

/**
 * @brief Starting position.
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
 * @brief Set the matrix to pre-execution state.
 */
void resetMatrix();

/**
 * @brief Set the matrix using the paths to the maps.
 */
void initMatrix();

// other useful functions

/**
 * @brief Set the flag _MapWasModified to 1.
 */
void declareMapWasModified();

/**
 * @brief Return the flag _MapWasModified and set the flag to 0.
 */
char wasModified();

#endif