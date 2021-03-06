#ifndef BOARD_H
#define BOARD_H

#include "Class.h"
#include "Grid.h"

#define BOARD_PROPS(self_t) \
    int (*input)(self_t *self, int column, void *piece); \
    void *(*remove)(Board *self, int column); \
    int (*is_column_valid)(self_t *self, int column); \
    int (*is_full)(self_t *self);

typedef struct _Board Board;

struct _Board {
    CLASS_PROPS(Board)
    GRID_PROPS(Board)
    BOARD_PROPS(Board)
};

Board *Board_new(int columns, int rows);
Board *Board_new_default(void);
void Board_apply(Board *self);
void Board_destroy(Board *self);
int Board_input(Board *self, int column, void *piece);
void *Board_remove(Board *self, int column);
int Board_is_column_valid(Board *self, int column);
int Board_is_full(Board *self);

#endif
