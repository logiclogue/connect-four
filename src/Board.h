#ifndef BOARD_H
#define BOARD_H
#define BOARD_PROPS(self_t) \
    char **state; \
    int rows; \
    int columns; \
    int (*input)(self_t *self, int column, char colour); \
    int (*is_column_valid)(Board *self, int column);
#define BOARD_EMPTY_TOKEN ' '

typedef struct _Board Board;

struct _Board {
    BOARD_PROPS(Board)
};

Board *Board_new(int columns, int rows);

#endif
