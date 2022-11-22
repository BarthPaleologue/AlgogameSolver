#ifndef matrix_h
#define matrix_h

enum Color {
    CASE_WHITE, CASE_RED, CASE_ORANGE, CASE_BLUE, CASE_STAR
};
//if you're on CASE_WHITE, you lose
//if you're on CASE_STAR, you win

extern char matrix[12][10];

#endif