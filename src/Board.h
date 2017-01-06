#ifndef BOARD_H
#define BOARD_H


typedef struct _Board Board;


#define BOARD_PROPS(self_t) \
    char **state; \
    int (*input)(self_t *self, char column, char colour);

#define BOARD_ROWS 6
#define BOARD_COLUMNS 7


typedef struct _Board {
    BOARD_PROPS(Board)
} Board;


Board *Board_new(void);


#endif
