#ifndef GAME_H
#define GAME_H

// This file is responsible for the state of the game

/**
 * @brief Inits the matrices and the remaining stars counter.
 *
 */
void initGlobals();

/**
 * @brief Resets the game state : map, coordinates, number of stars, function call stack.µ
 * Necessary before executing a new program.
 */
void initGame();

/**
 * Updates the map and the stars' counter if on a star.
 */
void eatStar();

/**
 * @brief Remaining stars.
 */
extern char nbRemainingStars;

/**
 * @brief Returns 1 if the player is on a white case, 0 otherwise.
 *
 * @return char 1 if the player is on a white case, 0 otherwise.
 */
char gameLost();

/**
 * @brief Returns 1 if the player has eaten all the stars, 0 otherwise.
 *
 * @return char 1 if the player has eaten all the stars, 0 otherwise.
 */
char gameWon();

#endif