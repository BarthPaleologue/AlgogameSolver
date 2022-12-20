#ifndef matrix_h
#define matrix_h


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
 * Current direction of the cursor.
*/
extern enum Direction direction;

void printCoords();

/**
 * @brief Prints the given matrix.
 * 
 * @param matrix
*/
void printMatrix(char ** matrix);

/**
 * @brief Current matrix modified by the program being executed.
*/
extern char ** matrix;



//INSTRUCTIONS' IMPLEMENTATION

//6 possible instructions' actions
void move();
void turnRight();
void turnLeft();
void paintRed();
void paintBlue();
void paintOrange();

//3 possible conditions on instructions
char isRed();
char isOrange();
char isBlue();


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