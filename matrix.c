#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "level_specifics.h"


//checks that the two maps are equivalent in terms of color
//sets the number of columns and lines
static char initMap();
char numberOfLines;
char numberOfColumns;
static char** matrixBase;
static char** matrixColorBase;

char** matrix;

struct Coords coords;
struct Coords startingCoords;
enum Direction direction;
char _gameTerminated = 0;
char _MapWasPainted = 0;
char numberOfStars;
char starsCounter;

//TODO : noter quelles variables globales sont modifiées pendant l'initialisation


void eatStar() {
    if (matrix[coords.y][coords.x] != CASE_STAR) {
        return;
    }
    matrix[coords.y][coords.x] = matrixColorBase[coords.y][coords.x];
    declareWasPainted();
    starsCounter--;
}

char gameLost() {
    return matrix[coords.y][coords.x] == CASE_WHITE;
}

char gameWon() {
    return (starsCounter == 0);
}

void declareWasPainted() {
    _MapWasPainted = 1;
}

char wasPainted() {
    //reads and resets the flag
    if (!_MapWasPainted) {
        return 0;
    }
    _MapWasPainted = 0;
    return 1;
}

void initMatrix() {

    if (!initMap()) {
        return;
    }

    matrixColorBase = malloc(numberOfLines * sizeof(char*));
    matrixBase = malloc(numberOfLines * sizeof(char*));
    matrix = malloc(numberOfLines * sizeof(char*));

    for (int i = 0; i < numberOfLines; i++) {
        matrixColorBase[i] = malloc(numberOfColumns * sizeof(char));
        matrixBase[i] = malloc(numberOfColumns * sizeof(char));
        matrix[i] = malloc(numberOfColumns * sizeof(char));
    }
    
    FILE * map = fopen(pathMap, "r");
    for (int i = 0; i < numberOfLines; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            char cell = fgetc(map);


            if (cell == '\n') {
                cell = fgetc(map);
            }

            switch(cell) {
                case '_':
                    matrixColorBase[i][j] = CASE_WHITE;
                    break;
                case 'R':
                    matrixColorBase[i][j] = CASE_RED;
                    break;
                case 'O':
                    matrixColorBase[i][j] = CASE_ORANGE;
                    break;
                case 'B':
                    matrixColorBase[i][j] = CASE_BLUE;
                    break;
                default:
                    printf("Error : invalid character in map file");
                    return;
            }
        }
    }

    fclose(map);

    FILE * starsMap = fopen(pathStarsMap, "r");
    for (int i = 0; i < numberOfLines; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            char cell = fgetc(starsMap);

            if (cell == '\n') {
                cell = fgetc(starsMap);
            }

            switch(cell) {
                case '_':
                    matrixBase[i][j] = CASE_WHITE;
                    break;
                case 'R':
                    matrixBase[i][j] = CASE_RED;
                    break;
                case 'O':
                    matrixBase[i][j] = CASE_ORANGE;
                    break;
                case 'B':
                    matrixBase[i][j] = CASE_BLUE;
                    break;
                case '*':
                    matrixBase[i][j] = CASE_STAR;
                    starsCounter++;
                    break;
                case 'X':
                    startingCoords.x = j;
                    startingCoords.y = i;
                    matrixBase[startingCoords.y][startingCoords.x] = matrixColorBase[startingCoords.y][startingCoords.x];
                    break;
                default:
                    printf("Error : invalid character in map file");
                    return;
            }
        }
    }

    fclose(starsMap);
    numberOfStars = starsCounter;
    printf("%daza\n", numberOfStars);
}

static char initMap() {
    FILE* map = fopen(pathMap, "r");
    FILE* starsMap = fopen(pathStarsMap, "r");
    if (map && starsMap) {

        char c1, c2;
        int columnsCounter = 0;

        while ((c1 = fgetc(map)) != EOF && (c2 = fgetc(starsMap)) != EOF) {
            //ne pas se prendre la tete : juste regarder si les char appartiennent au 4 / 5 permis... 
            printf("%c%c  ", c1, c2);

            if (c2 != ' ' && c2 != '\n' && c2 != '\r') {
                columnsCounter++;
            } else if (c2 == ' ' || c2 == '\r') {
                printf("There are spaces or tabs in the stars map file. Please remove them.\n");
                fclose(map);
                fclose(starsMap);
                return 0;
            } else {
                if (numberOfColumns != 0 && columnsCounter != numberOfColumns) {
                    printf("Check that there's the same number of symbols on each line of the star map.\n");
                    fclose(map);
                    fclose(starsMap);
                    return 0;
                } else {
                    numberOfLines++;
                    numberOfColumns = columnsCounter;
                    columnsCounter = 0;
                }
            }
            
            if (c2 != '*' && c2 != 'X' && c1 != c2) {
                if (c1 == ' ' || c1 == '\r') {
                    printf("There are spaces or tabs in the map file. Please remove them.\n");
                    fclose(map);
                    fclose(starsMap);
                    return 0;
                } else {
                    printf("The map and the star map are not conform. Please check that the symbols are the same.\n");
                    fclose(map);
                    fclose(starsMap);
                    return 0;
                }
            } else if (c2 == 'X' && c1 == 'X') {
                printf("There is an 'X' in the map file, only write one 'X' in the stars' map file.\n");
                fclose(map);
                fclose(starsMap);
                return 0;
            }
        }

        printf("Correspondance between the two files is correct\n");
        numberOfLines++;
        fclose(map);
        fclose(starsMap);
        return 1;

    } else {
        printf("Error while reading map files");
        fclose(map);
        fclose(starsMap);
        return 0;
    }
}


void resetMatrix() {
    for (int i = 0; i < numberOfLines; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            matrix[i][j] = matrixBase[i][j];
        }
    }
    //printMatrix(matrix);
}