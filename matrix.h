enum Color {
    CASE_WHITE, CASE_RED, CASE_ORANGE, CASE_BLUE, CASE_STAR
};
//if you're on CASE_WHITE, you lose
//if you're on CASE_STAR, you win

int matrix[12][10] = {
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
    {CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE, CASE_WHITE}
};