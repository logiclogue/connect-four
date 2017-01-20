#ifndef GRID_H
#define GRID_H

#include "Class.h"

#define GRID_PROPS(self_t) \
    char **grid; \
    int columns; \
    int rows; \
    char empty_square; \
    char (*get)(self_t *self, int column, int row); \
    int (*set)(self_t *self, int column, int row, char piece);

typedef struct _Grid Grid;

struct _Grid {
    CLASS_PROPS(Grid)
    GRID_PROPS(Grid)
};

Grid *Grid_new(int columns, int rows);
Grid *Grid_new_default(void);
void Grid_apply(Grid *self);
void Grid_destroy(Grid *self);

#endif
