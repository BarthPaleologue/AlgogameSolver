#ifndef GAME_H
#define GAME_H

// This file is responsible for the state of the game

/**
 * Updates the map and the stars' counter if on a star.
 */
void eatStar();

char gameLost();
char gameWon();

#endif