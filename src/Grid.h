#ifndef GRID_H
#define GRID_H

#include "Class.h"

#define GRID_PROPS(self_t) \
    void ***grid; \
    int columns; \
    int rows; \
    void *(*get)(self_t *self, int column, int row); \
    int (*set)(self_t *self, int column, int row, void *piece); \
    int (*is_in_range)(self_t *self, int column, int row);

typedef struct _Grid Grid;

struct _Grid {
    CLASS_PROPS(Grid)
    GRID_PROPS(Grid)
};

Grid *Grid_new(int columns, int rows);
Grid *Grid_new_default(void);
void Grid_apply(Grid *self, int columns, int rows);
void Grid_apply_default(Grid *self);
void Grid_destroy(Grid *self);
void *Grid_get(Grid *self, int column, int row);
int Grid_set(Grid *self, int column, int row, void *piece);
int Grid_is_in_range(Grid *self, int column, int row);

#endif
