#include <stdio.h>
#include "matrix.h"
#include "level_specifics.h"

static char isConformAndWhatSize(char nbOfLines, char nbOfColumns);

char matrixBase[12][10] = {
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_STAR, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_RED, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE},
    {CASE_WHITE, CASE_ORANGE, CASE_RED, CASE_RED, CASE_ORANGE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE},
    {CASE_WHITE, CASE_RED, CASE_ORANGE, CASE_RED, CASE_RED, CASE_RED, CASE_RED, CASE_RED, CASE_ORANGE, CASE_WHITE},
    {CASE_WHITE, CASE_RED, CASE_RED, CASE_WHITE, CASE_RED, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_RED, CASE_WHITE},
    {CASE_WHITE, CASE_ORANGE, CASE_RED, CASE_RED, CASE_ORANGE, CASE_RED, CASE_ORANGE, CASE_RED, CASE_RED, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_ORANGE, CASE_RED, CASE_RED, CASE_WHITE, CASE_RED, CASE_WHITE, CASE_RED, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_ORANGE, CASE_RED, CASE_RED, CASE_RED, CASE_ORANGE, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_RED, CASE_WHITE, CASE_WHITE, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_RED, CASE_ORANGE, CASE_WHITE, CASE_WHITE, CASE_WHITE},
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE}};

char matrix[12][10];

struct Coords coords = {5, 10};
enum Direction direction = RIGHT;
char _gameTerminated = 0;
char _WasPainted = 0;

void printCoords() {
    if (coords.x == 5 && coords.y == 10) {
        return;
    }
    printf("x : %d; y : %d\n", coords.x, coords.y);
}

void printMatrix(char matrix[12][10]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == coords.y && j == coords.x) {
                printf("X");
                continue;
            }
            switch (matrix[i][j]) {
                case CASE_WHITE:
                    printf(" ");
                    break;
                case CASE_RED:
                    printf("R");
                    break;
                case CASE_ORANGE:
                    printf("O");
                    break;
                case CASE_BLUE:
                    printf("B");
                    break;
                case CASE_STAR:
                    printf("*");
                    break;
                default:
                    printf("?");  // should never happen
            }
        }
        printf("\n");
    }
}

void move() {
    switch (direction) {
        case UP:
            coords.y--;
            break;
        case DOWN:
            coords.y++;
            break;
        case LEFT:
            coords.x--;
            break;
        case RIGHT:
            coords.x++;
            break;
    }
}

void turnRight() {
    direction = (direction + 1) % 4;
}

void turnLeft() {
    direction = (direction + 3) % 4;
}

char isRed() {
    return matrix[coords.y][coords.x] == CASE_RED;
}

char isOrange() {
    return matrix[coords.y][coords.x] == CASE_ORANGE;
}

char isBlue() {
    return matrix[coords.y][coords.x] == CASE_BLUE;
}

char isStar() {
    return matrix[coords.y][coords.x] == CASE_STAR;
}

void paintRed() {
    matrix[coords.y][coords.x] = CASE_RED;
}

void paintBlue() {
    matrix[coords.y][coords.x] = CASE_BLUE;
}

char gameLost() {
    return matrix[coords.y][coords.x] == CASE_WHITE;
}

char gameWon() {
    return (numberOfStars == 0);
}

void declareWasPainted() {
    _WasPainted = 1;
}

char wasPainted() {
    //reads and resets the flag
    if (!_WasPainted) {
        return 0;
    }
    _WasPainted = 0;
    return 1;
}

void declareGameTerminated() {
    _gameTerminated = 1;
}

char gameTerminated() {
    //reads and resets the flag
    if (!_gameTerminated) {
        return 0;
    }
    _gameTerminated = 0;
    return 1;
}

void initMatrix() {
    char nbOfLines;
    char nbOfColunms;

    if (!isConformAndWhatSize(nbOfLines, nbOfColunms)) {
        return;
    }


}

static char isConformAndWhatSize(char nbOfLines, char nbOfColumns) {
    FILE* map = fopen(pathMap, "r");
    FILE* starsMap = fopen(pathStarsMap, "r");
    if (map && starsMap) {

        char c1, c2;
        nbOfColumns = 0;
        int columnsCounter = 0;
        nbOfLines = 0;

        while ((c1 = fgetc(map)) != EOF && (c2 = fgetc(starsMap)) != EOF) {
            
            if (c2 != ' ' && c2 != '\n' && c2 != '\r') {
                columnsCounter++;
            } else if (c2 == ' ' || c2 == '\r') {
                printf("There are spaces or tabs in the stars map file. Please remove them.\n");
                return 0;
            } else {
                if (nbOfColumns != 0 && columnsCounter != nbOfColumns) {
                    printf("Check that there's the same number of symbols on each line of the star map.\n");
                    return 0;
                } else {
                    nbOfColumns = columnsCounter;
                    columnsCounter = 0;
                }
            }
            
            if (c2 != '*' && c1 != c2) {
                if (c1 == ' ' || c1 == '\r') {
                    printf("There are spaces or tabs in the map file. Please remove them.\n");
                    return 0;
                } else {
                    printf("The map and the star map are not conform. Please check that the symbols are the same.\n");
                    return 0;
                }
            } 
        }

        printf("Correspondance between the two files is correct\n");
        return 1;
        
    } else {
        printf("Error while reading map files");
        return 0;
    }
}


void resetMatrix() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = matrixBase[i][j];
        }
    }
}