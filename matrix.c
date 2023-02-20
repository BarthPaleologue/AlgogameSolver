#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

#include "colors.h"
#include "level_specifics.h"
#include "paths.h"

// checks that the two maps are equivalent in terms of color
// sets the number of columns and lines
static char areMapsWellFormatted();

unsigned int matrixHeight;
unsigned int matrixWidth;

/**
 * @brief The unaltered level matrix with stars.
 */
static char** matrixBackup;

char** matrixColorBackup;
char** matrix;

char numberOfStars;

struct Coords startingCoords;

char _gameTerminated = 0;
char _MapWasPainted = 0;

void declareWasPainted() { _MapWasPainted = 1; }

char wasPainted() {
    // reads and resets the flag
    if (!_MapWasPainted) return 0;
    _MapWasPainted = 0;
    return 1;
}

void initMatrix() {
    if (!areMapsWellFormatted()) return;

    // allocate memory for the matrices
    matrixColorBackup = malloc(matrixHeight * sizeof(char*));
    matrixBackup = malloc(matrixHeight * sizeof(char*));
    matrix = malloc(matrixHeight * sizeof(char*));

    for (unsigned int i = 0; i < matrixHeight; i++) {
        matrixColorBackup[i] = malloc(matrixWidth * sizeof(char));
        matrixBackup[i] = malloc(matrixWidth * sizeof(char));
        matrix[i] = malloc(matrixWidth * sizeof(char));
    }

    // white padding on first line and last line
    for (unsigned int j = 0; j < matrixWidth; j++) {
        matrixColorBackup[0][j] = CASE_WHITE;
        matrixColorBackup[matrixHeight - 1][j] = CASE_WHITE;

        matrixBackup[0][j] = CASE_WHITE;
        matrixBackup[matrixHeight - 1][j] = CASE_WHITE;
    }

    // white padding on first column and last column
    for (unsigned int i = 1; i < matrixHeight - 1; i++) {
        matrixColorBackup[i][0] = CASE_WHITE;
        matrixColorBackup[i][matrixWidth - 1] = CASE_WHITE;

        matrixBackup[i][0] = CASE_WHITE;
        matrixBackup[i][matrixWidth - 1] = CASE_WHITE;
    }

    // fill the colormap from file
    FILE* colorMap = fopen(pathMap, "r");

    for (unsigned int i = 1; i < matrixHeight - 1; i++) {
        for (unsigned int j = 1; j < matrixWidth - 1; j++) {
            char cell = fgetc(colorMap);

            if (cell == '\n') cell = fgetc(colorMap);

            switch (cell) {
                case '_':
                    matrixColorBackup[i][j] = CASE_WHITE;
                    break;
                case 'R':
                    matrixColorBackup[i][j] = CASE_RED;
                    break;
                case 'O':
                    matrixColorBackup[i][j] = CASE_ORANGE;
                    break;
                case 'B':
                    matrixColorBackup[i][j] = CASE_BLUE;
                    break;
                default:
                    printf(RED "Error : invalid character in map file : %c\n" RESET, cell);
                    return;
            }
        }
        matrixColorBackup[i][matrixWidth - 1] = CASE_WHITE;
    }

    fclose(colorMap);

    // fill the starmap from file
    FILE* starsMap = fopen(pathStarsMap, "r");

    for (unsigned int i = 1; i < matrixHeight - 1; i++) {
        for (unsigned int j = 1; j < matrixWidth - 1; j++) {
            char cell = fgetc(starsMap);

            if (cell == '\n') cell = fgetc(starsMap);

            switch (cell) {
                case '_':
                    matrixBackup[i][j] = CASE_WHITE;
                    break;
                case 'R':
                    matrixBackup[i][j] = CASE_RED;
                    break;
                case 'O':
                    matrixBackup[i][j] = CASE_ORANGE;
                    break;
                case 'B':
                    matrixBackup[i][j] = CASE_BLUE;
                    break;
                case '*':
                    matrixBackup[i][j] = CASE_STAR;
                    numberOfStars++;
                    break;
                case 'X':
                    startingCoords.x = j;
                    startingCoords.y = i;
                    matrixBackup[startingCoords.y][startingCoords.x] = matrixColorBackup[startingCoords.y][startingCoords.x];
                    break;
                default:
                    printf(BOLDRED "Error : invalid character in map file" RESET);
                    return;
            }
        }
    }

    fclose(starsMap);
}

static char areMapsWellFormatted() {
    printf(BOLDCYAN "Checking map formatting...\n" RESET);
    FILE* map = fopen(pathMap, "r");
    FILE* starsMap = fopen(pathStarsMap, "r");

    if (map && starsMap) {
        char c1, c2;
        unsigned int columnsCounter = 0;

        while ((c1 = fgetc(map)) != EOF && (c2 = fgetc(starsMap)) != EOF) {
            // check if the starmap is well formatted
            if (c2 == '_' || c2 == 'O' || c2 == 'R' || c2 == 'B' || c2 == 'X' || c2 == '*') {
                columnsCounter++;
            } else if (c2 == ' ' || c2 == '\r') {
                printf(BOLDRED "There are spaces or tabs in the stars map file. Please remove them.\n" RESET);
                fclose(map);
                fclose(starsMap);
                return 0;
            } else if (c2 == '\n') {
                if (matrixWidth != 0 && columnsCounter != matrixWidth) {
                    printf(BOLDRED "Check that there's the same number of symbols on each line of the star map.\n" RESET);
                    fclose(map);
                    fclose(starsMap);
                    return 0;
                } else {
                    matrixHeight++;
                    matrixWidth = columnsCounter;
                    columnsCounter = 0;
                }
            } else {
                printf(BOLDRED "There are other characters than _, O, R, B, *, X or \\n.Please remove them.\n" RESET);
                fclose(map);
                fclose(starsMap);
                return 0;
            }

            if (c1 != c2 && c2 != '*' && c2 != 'X') {
                if (c1 == ' ' || c1 == '\r') {
                    printf(BOLDRED "There are spaces or tabs in the map file. Please remove them.\n" RESET);
                    fclose(map);
                    fclose(starsMap);
                    return 0;
                } else {
                    printf(BOLDRED "The map and the star map are not conform. Please check that the symbols are the same.\n" RESET);
                    fclose(map);
                    fclose(starsMap);
                    return 0;
                }
            } else if (c1 == '*' || c1 == 'X') {
                printf(BOLDRED "There is an X or a * in the map file, only write * and one X in the stars' map file.\n" RESET);
                fclose(map);
                fclose(starsMap);
                return 0;
            }
        }

        printf(BOLDGREEN "\nThe map formatting is correct\n" RESET);
        matrixHeight++;
        matrixHeight = matrixHeight + 2;
        matrixWidth = matrixWidth + 2;
        fclose(map);
        fclose(starsMap);

        return 1;
    }
    fclose(map);
    fclose(starsMap);
    printf(BOLDRED "\n\nError while reading map files" RESET);

    return 0;
}

void resetMatrix() {
    for (unsigned int i = 0; i < matrixHeight; i++) {
        for (unsigned int j = 0; j < matrixWidth; j++) {
            matrix[i][j] = matrixBackup[i][j];
        }
    }
}