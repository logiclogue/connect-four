#ifndef BOARD_H
#define BOARD_H

#define BOARD_PROPS \
    char **board; \
    int (*input)(void *self, char column, char colour);

typedef struct _Board {
    BOARD_PROPS
} Board;

Board Board_new(void);

#endif
