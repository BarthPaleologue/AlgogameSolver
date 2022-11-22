enum Action {
    FORWARD,
    TURN_LEFT, TURN_RIGHT,
    PAINT_RED, PAINT_BLUE,
    F1, F2
};

enum Condition {
    LOST, RED, ORANGE, BLUE
};

struct Instruction {
    enum Action action;
    enum Condition condition;
};

typedef struct Instruction* Program;

Program generateNextProgram();