#ifndef matrix_h
#define matrix_h


/*The matrix knows where you are and how close you're to the goal. It also knows how to erase all you work to retry.*/
extern char numberOfLines;
extern char numberOfColumns;

enum Color {
    CASE_WHITE,
    CASE_RED,
    CASE_ORANGE,
    CASE_BLUE,
    CASE_STAR
};
// if you're on CASE_WHITE, you lose
// if you're on CASE_STAR, you win a star

//MOUVEMENTS ON THE MATRIX' IMPLEMENTATION

/**
 * @brief Direction in the map.
*/
enum Direction {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

/**
 * Current direction of the cursor.
*/
extern enum Direction direction;

/**
 * Coordinates on the map.
 * Careful, the position is at matrix[y][x].
*/
struct Coords {
    unsigned char x;
    unsigned char y;
};

/**
 * Current position of the cursor.
*/
extern struct Coords coords;

/**
 * Starting position.
*/
extern struct Coords startingCoords;


/**
 * @brief Current matrix modified by the program being executed.
*/
extern char ** matrix;



//GAME SUCCESS' WATCHERS

/**
 * @brief Total number of stars in the map.
*/
extern char numberOfStars;

/**
 * @brief Remaining stars.
*/
extern char starsCounter;


/**
 * Updates the map and the stars' counter if on a star.
*/
void eatStar();

char gameLost(); 
char gameWon();



//INITIALIZATIONS OF THE MATRIX

/**
 * @brief Sets the matrix using the paths to the maps.
*/
void resetMatrix();


/**
 * @brief Sets the matrix to pre-execution state.
*/
void initMatrix();

//other useful functions

/**
 * Sets the flag _MapWasPainted to 1.
*/
void declareWasPainted();

/**
 * Returns the flag _MapWasPainted and sets the flag to 0.
*/
char wasPainted();




#endif