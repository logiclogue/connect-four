#ifndef BOARD_H
#define BOARD_H
#define BOARD_PROPS(self_t) \
    char **state; \
    char *record; \
    int (*input)(self_t *self, int column, char colour);
#define BOARD_ROWS 6
#define BOARD_COLUMNS 7

typedef struct _Board Board;

struct _Board {
    BOARD_PROPS(Board)
};

Board *Board_new(void);

#endif
